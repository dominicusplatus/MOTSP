#ifndef TSPEVOSOLVERVIEWMODEL_H
#define TSPEVOSOLVERVIEWMODEL_H

#include <QObject>

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


class TspEvoSolverViewModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(eoPop <Route> population READ getPopulation WRITE setPopulation NOTIFY populationChanged)
public:
    explicit TspEvoSolverViewModel(QObject *parent = 0);
    void Solve();
    bool IsSolving();
    eoPop <Route> getPopulation();
signals:
    int DidSolveGeneration();
    void populationChanged(const eoPop <Route> &newPopulation);
public slots:
    void setPopulation(eoPop <Route> a);
private:
    eoPop <Route> m_population;
  //  eoEasyEA <Route> ea;
  //  eoGenContinue <Route> cont;
};

#endif // TSPEVOSOLVERVIEWMODEL_H
