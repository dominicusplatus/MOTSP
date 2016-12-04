#include "tspevosolverviewmodel.h"
#include "tspevofitnesshistorydatamodel.h"
#include <QtCore/QVector>
#include <QtCore/QTime>
#include <QtCore/QRect>
#include <QtGui/QColor>

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

TspEvoSolverViewModel::TspEvoSolverViewModel(QObject *parent) : QAbstractTableModel(parent)
{
 //   historyModel = new TspEvoFitnessHistoryDataModel(parent);
   // m_historyModel.bindToModel(m_data);
       m_populationsize = 25;
       m_columnCount = 2;
       m_generations = 50;
       m_mutationProb = 0.02;
       m_rowCount = m_populationsize;

       Solve();
}


void TspEvoSolverViewModel::Solve()
{
  //   ea (m_population);

    int popSize = (int)m_populationsize;

    Graph :: load ("/home/dominicus/Documents/INF/paretoevo/Src/TSP/benchs/test1.tsp") ; // Instance

    RouteInit init ; // Sol. Random Init.

    RouteEval full_eval ; // Full Evaluator



    eoPop <Route> pop(popSize, init) ; // Population
    TspRoutes = pop;

    apply <Route> (full_eval, pop) ;

    //std :: cout << "[From] " << pop.best_element () << std :: endl ;

    eoGenContinue <Route> cont(m_generations) ; /* Continuator (A fixed number of  100 iterations */

    eoStochTournamentSelect <Route> select_one ; // Selector

    eoSelectNumber <Route> select (select_one, popSize) ;

    //  OrderXover cross ; // Order Crossover
    PartialMappedXover cross ;

    CitySwap mut ; // City Swap Mutator

    eoSGATransform <Route> transform (cross, 1, mut, m_mutationProb) ;

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

       //beginRemoveRows();
        beginResetModel();

       m_data.clear();
      // endRemoveRows();

       //copy the results
       int pint = 0;
       // QVector<qreal>  vals;


       for(pint = 0; pint<pop.size();pint++){
           QVector<qreal> val;
           // val[0]= (qreal)pop[pint].EO.fitness();   //[0];

           val.push_back((qreal)pint);
           val.push_back((qreal)pop[pint].fitness());
           //val.push_back((qreal)pop[pint].fitness());
          // val.push_back((qreal)pop[pint].fitness());
           m_data.push_back(val);


          // val[1]= (qreal)pop[pint][1];
       //     m_data.push_back(val);
       }

       //m_data.push_back(vals);

     m_rowCount = m_populationsize;

     endResetModel();

     emit populationChanged(TspRoutes);

       QModelIndex indexA = this->index(0, 0, QModelIndex());
       QModelIndex indexC = this->index(m_populationsize, 1, QModelIndex());

       UpdateDataRange();

      // QModelIndex iend = QModelIndex(0,0);
       emit dataChanged(indexA, indexC);


       //emit historyModelChanged(m_historyModel);

  //  emit DidSolveGeneration(1);
}



void TspEvoSolverViewModel::SolveMultiObjectivePermutized()
{

    int popSize = (int)m_populationsize;

    Graph :: load ("/home/dominicus/Documents/INF/paretoevo/Src/TSP/benchs/test1.tsp") ; // Instance
    RouteInit init ; // Sol. Random Init.
    RouteEval full_eval ; // Full Evaluator

    eoPop <Route> pop(popSize, init) ; // Population
    TspRoutes = pop;

    apply <Route> (full_eval, pop) ;
    eoGenContinue <Route> cont(m_generations) ; /* Continuator (A fixed number of  100 iterations */
    eoStochTournamentSelect <Route> select_one ; // Selector
    eoSelectNumber <Route> select (select_one, popSize) ;

    PartialMappedXover cross ;
    CitySwap mut ; // City Swap Mutator
    eoSGATransform <Route> transform (cross, 1, mut, m_mutationProb) ;
    eoElitism <Route> merge (1) ; // Use of Elistism
    eoStochTournamentTruncate <Route> reduce (0.7) ; // Stoch. Replacement


    eoEasyEA <Route> ea (cont, full_eval, select, transform, merge, reduce) ;

    eoCheckPoint<Route> checkpoint(cont);
    eoValueParam<unsigned> generationCounter(0, "Generation");
    eoIncrementor<unsigned> increment(generationCounter.value());
    eoAverageStat<Route>  stat;
    checkpoint.add(stat);
    eoSecondMomentStats<Route> stats;

    checkpoint.add(stats);
     ea (pop);

       std :: cout << "[To] " << pop.best_element () << std :: endl ;

        beginResetModel();
       m_data.clear();
       int pint = 0;
       for(pint = 0; pint<pop.size();pint++){
           QVector<qreal> val;
           val.push_back((qreal)pint);
           val.push_back((qreal)pop[pint].fitness());
           m_data.push_back(val);
       }

     m_rowCount = m_populationsize;

     endResetModel();
     emit populationChanged(TspRoutes);
       QModelIndex indexA = this->index(0, 0, QModelIndex());
       QModelIndex indexC = this->index(m_populationsize, 1, QModelIndex());

       UpdateDataRange();
       emit dataChanged(indexA, indexC);
}


int TspEvoSolverViewModel::GetResult()
{
    int result = 0;

    //get first route
    if(TspRoutes.size() < 1){
        return 0;
    }

    int verts = Graph::size();

    int routes = TspRoutes.size();
    int rinc = 0;
    for(rinc=0; rinc<routes;rinc++){
        Route rt = TspRoutes[rinc];

        if(rt.size() < verts){

        }

        QPoint from, to, prev;

           //store first point
        std::pair <double, double> coordsFrom = Graph::getCityCoords(rt[0]);
        prev.setX(coordsFrom.first*3);
        prev.setY(coordsFrom.second*3);

        int sumLen = 0;
        int vertNo = 0;
        for (vertNo = 1; vertNo < verts; vertNo++)
        {
            to = QPoint();
            std::pair <double, double> coordsTo = Graph::getCityCoords(rt[vertNo]);
            to.setX( coordsTo.first *3);
            to.setY(coordsTo.second *3);

            int diffX = abs( to.x() - prev.x());
            int diffY = abs( to.y() - prev.y());

              sumLen += (int) ( sqrt( pow(diffX,2) + pow(diffY,2) ) );

            prev = to;
        }


        if(result ==0){
            result = sumLen;
            if(BestTspRoutes.size() == 0){
                BestTspRoutes.push_back(rt);
            }else{
                BestTspRoutes[0] = rt;
            }
        }
        else if (sumLen < result){
            result = sumLen;
            if(BestTspRoutes.size() == 0){
                BestTspRoutes.push_back(rt);
            }else{
                BestTspRoutes[0] = rt;
            }
        }


    }

        return  result;
}

void TspEvoSolverViewModel::SolveMOEO()
{
        int popSize = (int)m_populationsize;
        MORouteGraph :: load ("/home/dominicus/Documents/INF/paretoevo/Src/TSP/benchs/test1.tsp") ; // Instance

       // eoParser parser();  // for user-parameter reading
        eoState state;                // to keep all things allocated

        unsigned int MAX_GEN = 100; //parser.createParam((unsigned int)(100), "maxGen", "Maximum number of generations",'G',"Param").value();
        double P_CROSS = 1.0;   //parser.createParam(1.0, "pCross", "Crossover probability",'C',"Param").value();
        double EXT_P_MUT = 1.0; //parser.createParam(1.0, "extPMut", "External Mutation probability",'E',"Param").value();
        double INT_P_MUT = 0.083;   //parser.createParam(0.083, "intPMut", "Internal Mutation probability",'I',"Param").value();
        unsigned int VEC_SIZE = (unsigned int)(30); //parser.createParam((unsigned int)(30), "vecSize", "Genotype Size",'V',"Param").value();
        unsigned int NB_OBJ= (unsigned int)(2); //parser.createParam((unsigned int)(2), "nbObj", "Number of Objective",'N',"Param").value();
       // std::string OUTPUT_FILE = parser.createParam(std::string("dtlz_ibea"), "outputFile", "Path of the output file",'o',"Output").value();
        unsigned int EVAL = (unsigned int)(100);  //parser.createParam((unsigned int)(1), "eval", "Number of the ZDT evaluation fonction",'F',"Param").value();
        unsigned int NB_EVAL =(unsigned int)(50);    /// parser.createParam((unsigned int)(0), "nbEval", "Number of evaluation before Stop",'P',"Param").value();
        unsigned int TIME = (unsigned int)(0);  //parser.createParam((unsigned int)(0), "time", "Time(seconds) before Stop",'T',"Param").value();


        /*** the representation-dependent things ***/
         std::vector <bool> bObjectives(2);
         for (unsigned int i=0; i<2 ; i++)
             bObjectives[i]=true;

         moeoObjectiveVectorTraits::setup(2,bObjectives);

         // The fitness evaluation
         eoEvalFunc <TspDRoute> * eval;
         eval = new TspDualEval;

         //eoRealInitBounded <TspDRoute> init (bounds);
         TspDualXover xover;
         TspDualMutation  mutation; // (bounds, INT_P_MUT, 20);

         /*** the representation-independent things ***/
         // initialization of the population
         // stopping criteria

         eoGenContinue<TspDRoute> term(MAX_GEN);
         eoEvalFuncCounter<TspDRoute> evalFunc(*eval);
         eoCheckPoint<TspDRoute>* checkpoint;

      //  if (TIME > 0)
      //       checkpoint = new eoCheckPoint<TspDRoute>(*(new eoTimeContinue<TspDRoute>(TIME)));
       //  else if (NB_EVAL > 0)
             checkpoint = new eoCheckPoint<TspDRoute>(*(new eoEvalContinue<TspDRoute>(evalFunc, NB_EVAL)));

         checkpoint->add(term);

         // algorithm
         eoSGAGenOp < TspDRoute > op(xover, P_CROSS, mutation, EXT_P_MUT);
         moeoAdditiveEpsilonBinaryMetric < TSPObjectiveVector > metric;

         moeoIBEA<TspDRoute> algo(*checkpoint, evalFunc ,op, metric);

        //   moeoIBEA<TspDRoute> algo( evalFunc ,op, metric);
       //  eoPop<TspDRoute>& pop = do_make_pop(parser, state, init);

         TspDRouteInit drouteInit ; // Sol. Random Init.

         eoPop <TspDRoute> pop(m_populationsize, drouteInit) ; // Population


         do_run(algo, pop);
         moeoUnboundedArchive<TspDRoute> finalArchive;
         finalArchive(pop);

         //now update the UI
          beginResetModel();
         m_data.clear();
         int pint = 0;
         for(pint = 0; pint<pop.size();pint++){
             QVector<qreal> val;
             val.push_back((qreal)pint);
             val.push_back((qreal)pop[pint].fitness());
             m_data.push_back(val);
         }

       m_rowCount = m_populationsize;

       endResetModel();
       emit populationChanged(TspRoutes);
         QModelIndex indexA = this->index(0, 0, QModelIndex());
         QModelIndex indexC = this->index(m_populationsize, 1, QModelIndex());

         UpdateDataRange();
         emit dataChanged(indexA, indexC);

}

/*
void SolveTspDual()
{
        unsigned argc;
        char **argv;
        eoParser parser(argc, argv);  // for user-parameter reading
        eoState state;                // to keep all things allocated

        // The fitness evaluation
        eoEvalFuncCounter<TspDRoute>& eval = do_make_eval(state);
        // the genotype (through a genotype initializer)
        eoInit<TspDRoute>& init = do_make_genotype(state);
        // the variation operators
        eoGenOp<TspDRoute>& op = do_make_op(state);

        // initialization of the population
        eoPop<TspDRoute>& pop = do_make_pop(parser, state, init);
        // definition of the archive
        moeoUnboundedArchive<TspDRoute> arch;

        // stopping criteria
        eoContinue<TspDRoute>& term = do_make_continue_moeo(parser, state, eval);
        // output
        eoCheckPoint<TspDRoute>& checkpoint = do_make_checkpoint_moeo(parser, state, eval, term, pop, arch);
        // algorithm
        eoAlgo<TspDRoute>& algo = do_make_ea_moeo(parser, state, eval, checkpoint, op, arch);


        // first evalution
        apply<TspDRoute>(eval, pop);

        // run the algo
        do_run(algo, pop);
}
*/

bool TspEvoSolverViewModel::IsSolving()
{
    return false;
}

eoPop <Route> TspEvoSolverViewModel::getPopulation()
{
    return TspRoutes;
}

void TspEvoSolverViewModel::setPopulation(eoPop <Route> a)
{
   // m_population = a;
}

void TspEvoSolverViewModel::setpopulationSize(qreal a)
{
    m_populationsize = a;
}

void TspEvoSolverViewModel::setGenerations(qreal a)
{
    m_generations = a;
}

void TspEvoSolverViewModel::setMutationProb(qreal a)
{
    m_mutationProb = a;
}

void TspEvoSolverViewModel::setfitnessRangeStart(qreal a)
{
    m_fitnessRangeStart = a;
}

void TspEvoSolverViewModel::setfitnessRangeEnd(qreal a)
{
    m_fitnessRangeEnd = a;
}

 qreal TspEvoSolverViewModel::getpopulationSize()
 {
        return m_populationsize;
 }

 qreal TspEvoSolverViewModel::getGenerations()
 {
        return m_generations;
 }

 qreal TspEvoSolverViewModel::getMutationProb()
 {
        return m_mutationProb;
 }

 qreal TspEvoSolverViewModel::getfitnessRangeStart()
 {
        return m_fitnessRangeStart;
 }


 qreal TspEvoSolverViewModel::getfitnessRangeEnd()
 {
        return m_fitnessRangeEnd;
 }

 TspEvoFitnessHistoryDataModel* TspEvoSolverViewModel::gethistoryModel()
 {
    return &m_historyModel;
 }

 void TspEvoSolverViewModel::sethistoryModel(TspEvoFitnessHistoryDataModel* a)
 {
  //  m_historyModel = a;
 }

 int TspEvoSolverViewModel::rowCount(const QModelIndex &parent) const
 {
     Q_UNUSED(parent)
     return m_data.count();
 }

 int TspEvoSolverViewModel::columnCount(const QModelIndex &parent) const
 {
     Q_UNUSED(parent)
     return m_columnCount;
 }

void TspEvoSolverViewModel::UpdateDataRange()
{
    int pinc =0;
    for(pinc =0; pinc < m_populationsize; pinc++){
         QVector<qreal> val = m_data[pinc];
         qreal len = val[1];
         if( (int)m_fitnessRangeEnd==0){
            m_fitnessRangeEnd = len;
            m_fitnessRangeStart = len;
            emit fitnessRangeStartChanged(m_fitnessRangeStart);
            emit fitnessRangeEndChanged(m_fitnessRangeEnd);
         }

         if(len<m_fitnessRangeStart){
             m_fitnessRangeStart =len;
             emit fitnessRangeStartChanged(m_fitnessRangeStart);
         }
         if( (len > m_fitnessRangeEnd)){
             m_fitnessRangeEnd = len;
             emit fitnessRangeEndChanged(m_fitnessRangeEnd);
         }

    }
}

 QVariant TspEvoSolverViewModel::headerData(int section, Qt::Orientation orientation, int role) const
 {
     if (role != Qt::DisplayRole)
         return QVariant();

     if (orientation == Qt::Horizontal) {
         if (section % 2 == 0)
             return "x";
         else
             return "y";
     } else {
         return QString("%1").arg(section + 1);
     }
 }

 QVariant TspEvoSolverViewModel::data(const QModelIndex &index, int role) const
 {
     if (role == Qt::DisplayRole) {
         return m_data[index.row()][index.column()];     //->at(index.column());
     } else if (role == Qt::EditRole) {
         return m_data[index.row()][index.column()]; //->at(index.column());
     } else if (role == Qt::BackgroundRole) {
         foreach (QRect rect, m_mapping) {
             if (rect.contains(index.column(), index.row()))
                 return QColor(m_mapping.key(rect));
         }
         // cell not mapped return white color
         return QColor(Qt::white);
     }
     return QVariant();
 }

 bool TspEvoSolverViewModel::setData(const QModelIndex &index, const QVariant &value, int role)
 {
     if (index.isValid() && role == Qt::EditRole) {
         m_data[index.row()][index.column()] =  value.toDouble();
         emit dataChanged(index, index);
         return true;
     }
     return false;
 }

 Qt::ItemFlags TspEvoSolverViewModel::flags(const QModelIndex &index) const
 {
     return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
 }

 void TspEvoSolverViewModel::addMapping(QString color, QRect area)
 {
     m_mapping.insertMulti(color, area);
 }



