#ifndef TSPEVOSOLVERVIEWMODEL_H
#define TSPEVOSOLVERVIEWMODEL_H

#include <QObject>
#include "QVector"
#include <QtCore/QAbstractTableModel>
#include <QtCore/QHash>
#include <QtCore/QRect>

#include <eoEasyEA.h>
#include <eoGenContinue.h>
#include <eoStochTournamentSelect.h>
#include <eoSGATransform.h>
#include <eoSelectNumber.h>

#include <moeo>

#include "graph.h"
#include "route.h"
#include "route_init.h"
#include "route_eval.h"
#include "order_xover.h"
#include "partial_mapped_xover.h"
#include "city_swap.h"

// include package checkpointing
#include <utils/checkpointing>

#include "tspevofitnesshistorydatamodel.h"


class TspEvoSolverViewModel : public QAbstractTableModel
{
    Q_OBJECT
    Q_PROPERTY(eoPop <Route> population READ getPopulation WRITE setPopulation NOTIFY populationChanged)
    Q_PROPERTY(qreal populationSize READ getpopulationSize WRITE setpopulationSize NOTIFY populationSizeChanged)
    Q_PROPERTY(TspEvoFitnessHistoryDataModel* historyModel READ gethistoryModel WRITE sethistoryModel NOTIFY historyModelChanged)
public:
    explicit TspEvoSolverViewModel(QObject *parent = 0);
    Q_INVOKABLE void Solve();
    bool IsSolving();
    eoPop <Route> getPopulation();
    qreal getpopulationSize();
    TspEvoFitnessHistoryDataModel* gethistoryModel();

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);
    Qt::ItemFlags flags(const QModelIndex &index) const;
    void bindToModel( QList<QVector<qreal>> data);

    void addMapping(QString color, QRect area);
    void clearMapping() { m_mapping.clear(); }


signals:
    int DidSolveGeneration();
    void populationChanged(const eoPop <Route> &newPopulation);
    void populationSizeChanged(const qreal &newSize);
    void historyModelChanged(const TspEvoFitnessHistoryDataModel* &newSize);
public slots:
    void setPopulation(eoPop <Route> a);
    void setpopulationSize(qreal a);
    void sethistoryModel(TspEvoFitnessHistoryDataModel* a);
private:
    eoPop <Route> m_population;
    qreal m_populationsize;
    TspEvoFitnessHistoryDataModel m_historyModel;

    QList<QVector<qreal>> m_data;
   QHash<QString, QRect> m_mapping;
   int m_columnCount;
   int m_rowCount;
  //  eoEasyEA <Route> ea;
  //  eoGenContinue <Route> cont;
};

#endif // TSPEVOSOLVERVIEWMODEL_H
