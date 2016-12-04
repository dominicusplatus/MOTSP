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

#include "tspdataservice.h"
#include "tspevofitnesshistorydatamodel.h"


class TspEvoSolverViewModel : public QAbstractTableModel
{
    Q_OBJECT
    Q_PROPERTY(eoPop <Route> population READ getPopulation WRITE setPopulation NOTIFY populationChanged)
    Q_PROPERTY(qreal populationSize READ getpopulationSize WRITE setpopulationSize NOTIFY populationSizeChanged)
    Q_PROPERTY(qreal generations READ getGenerations WRITE setGenerations NOTIFY generationsChanged)
    Q_PROPERTY(qreal mutationProb READ getMutationProb WRITE setMutationProb NOTIFY mutationProbChanged)
    Q_PROPERTY(qreal fitnessRangeStart READ getfitnessRangeStart WRITE setfitnessRangeStart NOTIFY fitnessRangeStartChanged)
    Q_PROPERTY(qreal fitnessRangeEnd READ getfitnessRangeEnd WRITE setfitnessRangeEnd NOTIFY fitnessRangeEndChanged)
    Q_PROPERTY(TspEvoFitnessHistoryDataModel* historyModel READ gethistoryModel WRITE sethistoryModel NOTIFY historyModelChanged)
public:
    explicit TspEvoSolverViewModel(QObject *parent = 0);
    Q_INVOKABLE void Solve();
    Q_INVOKABLE void SolveMOEO();
    Q_INVOKABLE  int GetResult();
  //  Q_INVOKABLE void SolveTspDual();
   Q_INVOKABLE  void SolveMultiObjectivePermutized();
    bool IsSolving();
    eoPop <Route> getPopulation();
    qreal getpopulationSize();
    qreal getGenerations();
    qreal getMutationProb();
    qreal getfitnessRangeStart();
    qreal getfitnessRangeEnd();
    TspEvoFitnessHistoryDataModel* gethistoryModel();
    void UpdateDataRange();


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
    void generationsChanged(const qreal &newSize);
    void mutationProbChanged(const qreal &newSize);
    void fitnessRangeStartChanged(const qreal &newSize);
    void fitnessRangeEndChanged(const qreal &newSize);
    void historyModelChanged(const TspEvoFitnessHistoryDataModel* &newSize);
public slots:
    void setPopulation(eoPop <Route> a);
    void setpopulationSize(qreal a);
    void setGenerations(qreal a);
    void setMutationProb(qreal a);
    void setfitnessRangeStart(qreal a);
    void setfitnessRangeEnd(qreal a);
    void sethistoryModel(TspEvoFitnessHistoryDataModel* a);
private:
   // eoPop <Route> m_population;
    qreal m_populationsize;
    qreal m_generations;
    qreal m_mutationProb;
    qreal m_fitnessRangeStart;
    qreal m_fitnessRangeEnd;
    TspEvoFitnessHistoryDataModel m_historyModel;

    QList<QVector<qreal>> m_data;
   QHash<QString, QRect> m_mapping;
   int m_columnCount;
   int m_rowCount;
  //  eoEasyEA <Route> ea;
  //  eoGenContinue <Route> cont;
};

#endif // TSPEVOSOLVERVIEWMODEL_H
