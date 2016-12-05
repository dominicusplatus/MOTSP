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
#include <QtCore/QVector>
#include <QtCore/QTime>
#include <QtCore/QRect>
#include <QtGui/QColor>

// include package checkpointing
#include <utils/checkpointing>

#include "tspdataservice.h"
#include "tspevofitnesshistorydatamodel.h"
#include "MOEO/tspdroute.h"
#include "tspevofitnesshistorydatamodel.h"


#include <moeo>
#include <es/eoRealInitBounded.h>

#include "MOEO/polynomialmutation.h"
#include "MOEO/sbxcrossover.h"
#include "MOEO/tspobjectivevector.h"
#include "MOEO/tspdroute.h"

// how to initialize the population
#include <do/make_pop.h>
// the stopping criterion
#include <do/make_continue_moeo.h>
// outputs (stats, population dumps, ...)
#include <do/make_checkpoint_moeo.h>
// evolution engine (selection and replacement)
#include <do/make_ea_moeo.h>
// simple call to the algo
#include <do/make_run.h>

#include "tspeval.h"
#include "MOEO/tspxoverdual.h"
#include "tspdrouteinit.h"
#include "tspdualdatahelpers.h"
#include "moroutegraph.h"
#include "tspgenerationevaluationcheckpoint.h"
#include "tspgenerationprogressmonitor.h"
#include "MOEO/tspdroute.h"
#include "tspdualdatahelpers.h"


class TspEvoSolverViewModel : public QAbstractTableModel
{
    Q_OBJECT
    Q_PROPERTY(eoPop <TspDRoute> population READ getPopulation WRITE setPopulation NOTIFY populationChanged)
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
    bool IsSolving();
    eoPop <TspDRoute> getPopulation();
    qreal getpopulationSize();
    qreal getGenerations();
    qreal getMutationProb();
    qreal getfitnessRangeStart();
    qreal getfitnessRangeEnd();
    TspEvoFitnessHistoryDataModel* gethistoryModel();
    void UpdateDataRange();
    TspDRoute GetPopulationBestRoute(eoPop<TspDRoute> pop);
    void ProcessPopulationHistory();

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
    void populationChanged(const eoPop <TspDRoute> &newPopulation);
    void populationSizeChanged(const qreal &newSize);
    void generationsChanged(const qreal &newSize);
    void mutationProbChanged(const qreal &newSize);
    void fitnessRangeStartChanged(const qreal &newSize);
    void fitnessRangeEndChanged(const qreal &newSize);
    void historyModelChanged(const TspEvoFitnessHistoryDataModel* &newSize);
public slots:
    void setPopulation(eoPop <TspDRoute> a);
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
    QList<qreal> moeoFitnessBestHistory;
    QList<TspDRoute> moeoBestRouteHistory;
    QList<qreal> moeoFitnessAverageHistory;
    QHash<QString, QRect> m_mapping;
    int m_columnCount;
    int m_rowCount;
  //  eoEasyEA <Route> ea;
  //  eoGenContinue <Route> cont;
};

#endif // TSPEVOSOLVERVIEWMODEL_H
