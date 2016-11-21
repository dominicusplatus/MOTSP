#include "tspevosolverviewmodel.h"

TspEvoSolverViewModel::TspEvoSolverViewModel(QObject *parent) : QObject(parent)
{
    Graph :: load ("/home/dominicus/Documents/TSP/benchs/ali535.tsp") ; // Instance

    RouteInit init ; // Sol. Random Init.

    RouteEval full_eval ; // Full Evaluator

    eoPop <Route> pop(100, init) ; // Population
    m_population = pop;

    apply <Route> (full_eval, pop) ;

    //std :: cout << "[From] " << pop.best_element () << std :: endl ;

    eoGenContinue <Route> cont(100) ; /* Continuator (A fixed number of
                       100 iterations */

    eoStochTournamentSelect <Route> select_one ; // Selector

    eoSelectNumber <Route> select (select_one, 100) ;

    //  OrderXover cross ; // Order Crossover
    PartialMappedXover cross ;

    CitySwap mut ; // City Swap Mutator

    eoSGATransform <Route> transform (cross, 1, mut, 0.01) ;

    eoElitism <Route> merge (1) ; // Use of Elistism

    eoStochTournamentTruncate <Route> reduce (0.7) ; // Stoch. Replacement

    eoEasyEA <Route> ea (cont, full_eval, select, transform, merge, reduce) ;

    /// LIVE UPDATE

    eoCheckPoint<Route> checkpoint(cont);

    // Create a counter parameter
    eoValueParam<unsigned> generationCounter(0, "Generation");

    // Create an incrementor (wich is an eoUpdater). Note that the
    // Parameter's value is passed by reference, so every time the incrementer increments,
    // the data in generationCounter will change.
    eoIncrementor<unsigned> increment(generationCounter.value());

    eoAverageStat<Route>  stat;

    // Add it to the checkpoint, this will result in the counter being incremented every generation
    checkpoint.add(stat);

    // the monitor can monitor parameters such as the generationCounter
    //stat.add(generationCounter);

    // Second moment stats: average and stdev
    eoSecondMomentStats<Route> stats;

    // Add it to the checkpoint to get it called at the appropriate time
    checkpoint.add(stats);

    // save state every third generation
    //eoCountedStateSaver stateSaver1(3, state, "generation");

    // And add the two savers to the checkpoint
  //  checkpoint.add(stateSaver1);

     ea (pop);

       std :: cout << "[To] " << pop.best_element () << std :: endl ;
}


void TspEvoSolverViewModel::Solve()
{
  //   ea (m_population);

     emit populationChanged(m_population);
  //  emit DidSolveGeneration(1);
}

bool TspEvoSolverViewModel::IsSolving()
{
    return false;
}

eoPop <Route> TspEvoSolverViewModel::getPopulation()
{
    return m_population;
}

void TspEvoSolverViewModel::setPopulation(eoPop <Route> a)
{
   // m_population = a;
}
