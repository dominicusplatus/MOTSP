#include "tspevosolverviewmodel.h"


 void TspEvoSolverViewModel::SetMethod(int id)
 {
    solverAlgorithm = (MoSolverAlgorithm)id;
 }

 void TspEvoSolverViewModel::SetDataset(int id)
 {
    dataSet = (TspDataset)id;
 }


TspEvoSolverViewModel::TspEvoSolverViewModel(QObject *parent) : QAbstractTableModel(parent)
{
 //   historyModel = new TspEvoFitnessHistoryDataModel(parent);
   // m_historyModel.bindToModel(m_data);
       m_populationsize = 40;
       m_columnCount = 4;
       m_generations = 400;
       m_mutationProb = 0.02;
       m_rowCount = m_populationsize;

       Solve();
}


void TspEvoSolverViewModel::Solve()
{
    /*
    int popSize = (int)m_populationsize;
    Graph :: load ("/home/dominicus/Documents/INF/paretoevo/Src/TSP/benchs/ali535.tsp") ; // Instance
    RouteInit init ; // Sol. Random Init.
    RouteEval full_eval ; // Full Evaluator
    eoPop <TspDRoute> pop(popSize, init) ; // Population
    TspRoutes = pop;

    apply <TspDRoute> (full_eval, pop) ;
    eoGenContinue <TspDRoute> cont(m_generations) ;
    eoStochTournamentSelect <TspDRoute> select_one ; // Selector
    eoSelectNumber <TspDRoute> select (select_one, popSize) ;

    //  OrderXover cross ; // Order Crossover
    PartialMappedXover cross ;
    CitySwap mut ; // City Swap Mutator
    eoSGATransform <TspDRoute> transform (cross, 1, mut, m_mutationProb) ;
    eoElitism <TspDRoute> merge (1) ; // Use of Elistism
    eoStochTournamentTruncate <TspDRoute> reduce (0.7) ; // Stoch. Replacement
    eoEasyEA <TspDRoute> ea (cont, full_eval, select, transform, merge, reduce) ;
    eoCheckPoint<TspDRoute> checkpoint(cont);

    // Create a counter parameter
    eoValueParam<unsigned> generationCounter(0, "Generation");
    eoIncrementor<unsigned> increment(generationCounter.value());

    eoAverageStat<TspDRoute>  stat;
    checkpoint.add(stat);
    eoSecondMomentStats<TspDRoute> stats;
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
*/
}



int TspEvoSolverViewModel::GetResult()
{
  return 0;
}





TspDRoute TspEvoSolverViewModel::GetPopulationBestRoute(eoPop<TspDRoute> pop)
{
    int result = 0;
     TspDRoute best;

    //get first route
    if(pop.size() < 1){
        return best;
    }

    int verts = MORouteGraph::size();
     best = pop[0];

    int routes = pop.size();
    int rinc = 0;
    for(rinc=0; rinc<routes;rinc++){
        TspDRoute rt = pop[rinc];
        TspDualEval eval;
        double routeLen = eval.length(rt);
        if(routeLen < eval.length(best) ){
            best = rt;
        }

    }

        return  best;
}


void TspEvoSolverViewModel::SolveMOEO()
{
    QString problemPath;
    if(dataSet == ALI535){
            MORouteGraph :: load ("/home/dominicus/Documents/INF/paretoevo/Src/TSP/benchs/ali535.tsp") ; // Instance
    }
    else if (dataSet == ELI101)
    {
            MORouteGraph :: load ("/home/dominicus/Documents/INF/paretoevo/Src/TSP/benchs/eil101.tsp") ; // Instance
    }
    else if (dataSet == PR2392)
    {
            MORouteGraph :: load ("/home/dominicus/Documents/INF/paretoevo/Src/TSP/benchs/pr2392.tsp") ; // Instance
    }
    else if (dataSet == RL5915)
    {
            MORouteGraph :: load ("/home/dominicus/Documents/INF/paretoevo/Src/TSP/benchs/rl5915.tsp") ; // Instance
    }
    else if (dataSet == USA13509)
    {
            MORouteGraph :: load ("/home/dominicus/Documents/INF/paretoevo/Src/TSP/benchs/usa13509.tsp") ; // Instance
    }
    else if (dataSet == ATH1)
    {
            MORouteGraph :: load ("/home/dominicus/Documents/INF/paretoevo/Src/TSP/benchs/test1.tsp") ; // Instance
    }
    else if (dataSet == ATH2)
    {
            MORouteGraph :: load ("/home/dominicus/Documents/INF/paretoevo/Src/TSP/benchs/test2.tsp") ; // Instance
    }



        eoState state;                // to keep all things allocated

        double P_CROSS = 1.0;
        double EXT_P_MUT = 1.0;
        double INT_P_MUT = 0.083;
        unsigned int VEC_SIZE = (unsigned int)(30);
        unsigned int NB_OBJ= (unsigned int)(2);
        unsigned int ARC_SIZE =  100;
        unsigned int K = (10);

        TspRoutePopulationsHistory.clear();
        TspRouteHistory.clear();
        BestTspRoutes.clear();


        /*** the representation-dependent things ***/
         std::vector <bool> bObjectives(2);
         for (unsigned int i=0; i<2 ; i++)
             bObjectives[i]=true;

         moeoObjectiveVectorTraits::setup(2,bObjectives);
         eoEvalFunc <TspDRoute> * eval;
         eval = new TspDualEval;

         TspDualXover xover;
         TspDualMutation  mutation; // (bounds, INT_P_MUT, 20);

         eoGenContinue<TspDRoute> term(m_generations);
         eoEvalFuncCounter<TspDRoute> evalFunc(*eval);
         eoCheckPoint<TspDRoute>* checkpoint;

         eoStdoutMonitor mon;
         checkpoint = new eoCheckPoint<TspDRoute>(term);
         TspGenerationEvaluationCheckpoint popChkpt;
         checkpoint->add(popChkpt);

         eoSGAGenOp < TspDRoute > op(xover, P_CROSS, mutation, EXT_P_MUT);
         moeoAdditiveEpsilonBinaryMetric < TSPObjectiveVector > metric;


         TspDRouteInit drouteInit ; // Sol. Random Init.
         eoPop <TspDRoute> pop(m_populationsize, drouteInit) ; // Population
         if(solverAlgorithm == IBEA ){
                moeoIBEA<TspDRoute> algo(*checkpoint, evalFunc ,op, metric) ;
                 do_run(algo, pop);
         }
         else if (solverAlgorithm == SPEA2 ){
                moeoSPEA2Archive<TspDRoute> arch(ARC_SIZE);
                moeoSPEA2<TspDRoute> algo(*checkpoint, evalFunc ,xover, P_CROSS, mutation, EXT_P_MUT, arch, K, false);
                  do_run(algo, pop);
         }
         else if (solverAlgorithm == NSGA ){
            moeoNSGA<TspDRoute> algo(*checkpoint, evalFunc ,op);
              do_run(algo, pop);
         }
         else if (solverAlgorithm == NSGAII ){
             moeoNSGAII<TspDRoute> algo(*checkpoint, evalFunc ,op);
              do_run(algo, pop);
         }
         else if (solverAlgorithm == MOGA ){
               //    moeoMOGA (unsigned int _maxGen, eoEvalFunc < MOEOT > & _eval, eoQuadOp < MOEOT > & _crossover, double _pCross, eoMonOp < MOEOT > & _mutation, double _pMut, double _nicheSize = 0.5) :
               moeoMOGA<TspDRoute> algo(*checkpoint, evalFunc ,op, 1) ;
                do_run(algo, pop);
           }

         else{
             return;
         }
/*
         else if (solverAlgorithm == SEEA ){
             moeoSPEA2Archive<TspDRoute> arch(ARC_SIZE);
             moeoSEEA<TspDRoute> algo(*checkpoint, evalFunc ,op, metric) ;
              do_run(algo, pop);
         }
  */

         moeoUnboundedArchive<TspDRoute> finalArchive;
         finalArchive(pop);
         TspRoutes = pop;
         //now update the UI
          beginResetModel();
         lengthHistory.clear();

       m_rowCount = m_generations;
       ProcessPopulationHistory();
       endResetModel();

         emit populationChanged(TspRoutes);
         QModelIndex indexA = this->index(0, 0, QModelIndex());
         QModelIndex indexC = this->index(m_generations, 1, QModelIndex());

         UpdateDataRange();
         emit dataChanged(indexA, indexC);


}

void  TspEvoSolverViewModel::ProcessPopulationHistory()
{
     moeoRouteLengthBestHistory.clear();
     moeoFitnessAverageHistory.clear();
     moeoRouteCostBestHistory.clear();
    //    QList<qreal> moeoRouteLengthBestHistory;
    //     QList<qreal> moeoRouteCostBestHistory;
     if(TspRoutePopulationsHistory.size() < 1){
         return;
     }

     //find best fitness for each generation
    int ginc =0;
    for(ginc=0; ginc<TspRoutePopulationsHistory.size();ginc++)
    {
        eoPop<TspDRoute> pop = TspRoutePopulationsHistory[ginc];
        TspDRoute bestroute = GetPopulationBestRoute(pop);
        moeoBestRouteHistory.push_back(bestroute);

        TspDualEval eval;
        double routeLen = eval.length(bestroute);
        double routeCost = eval.cost(bestroute);
        moeoRouteLengthBestHistory.push_back( routeLen );
        moeoRouteCostBestHistory.push_back( routeCost );

        QVector<qreal> val;
        val.push_back((qreal)ginc);
        val.push_back((qreal)routeLen);
        lengthHistory.push_back(val);

        QVector<qreal> val2;
        val2.push_back((qreal)ginc);
        val2.push_back((qreal)routeCost);
        costHistory.push_back(val2);

    }

}


bool TspEvoSolverViewModel::IsSolving()
{
    return false;
}

eoPop <TspDRoute> TspEvoSolverViewModel::getPopulation()
{
    return TspRoutes;
}

void TspEvoSolverViewModel::setPopulation(eoPop <TspDRoute> a)
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

void TspEvoSolverViewModel::setcostsRangeStart(qreal a)
{
    m_costsRangeStart = a;
}

void TspEvoSolverViewModel::setcostsRangeEnd(qreal a)
{
    m_costsRangeEnd = a;
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

 qreal TspEvoSolverViewModel::getcostsRangeStart()
 {
        return m_costsRangeStart;
 }

 qreal TspEvoSolverViewModel::getcostsRangeEnd()
 {
        return m_costsRangeEnd;
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
     return lengthHistory.count();
 }

 int TspEvoSolverViewModel::columnCount(const QModelIndex &parent) const
 {
     Q_UNUSED(parent)
     return m_columnCount;
 }




void TspEvoSolverViewModel::UpdateDataRange()
{

    m_fitnessRangeEnd=0;
    m_fitnessRangeStart  =0;

    m_costsRangeEnd=0;
    m_costsRangeStart = 0;

    int pinc =0;
    for(pinc =0; pinc < lengthHistory.size(); pinc++){
         QVector<qreal> val = lengthHistory[pinc];
         qreal len = val[1];
         if( (int)m_fitnessRangeEnd==0){
            m_fitnessRangeEnd = len;
            m_fitnessRangeStart = len;
            minimumCostLength= len;
            maximumCostLength = len;
            emit fitnessRangeStartChanged(m_fitnessRangeStart);
            emit fitnessRangeEndChanged(m_fitnessRangeEnd);
         }

         if(len<m_fitnessRangeStart){
             m_fitnessRangeStart =len;
             minimumCostLength = len;
             emit fitnessRangeStartChanged(m_fitnessRangeStart);
         }
         if( (len > m_fitnessRangeEnd)){
             m_fitnessRangeEnd = len;
             maximumCostLength = len;
             emit fitnessRangeEndChanged(m_fitnessRangeEnd);
         }

    }


    for(pinc =0; pinc < costHistory.size(); pinc++){
         QVector<qreal> val = costHistory[pinc];
         qreal len = val[1];
         if( m_costsRangeEnd==0 ){
            m_costsRangeEnd = len;
            m_costsRangeStart = len;

            minimumCostPath = len;
            maximumCostPath = len;
            emit costsRangeStartChanged(m_costsRangeStart);
            emit costsRangeEndChanged(m_costsRangeEnd);
         }

         if(len<m_costsRangeStart){
             m_costsRangeStart =len;
             minimumCostPath = len;
             emit costsRangeStartChanged(m_costsRangeStart);
         }
         if( (len > m_costsRangeEnd)){
             m_costsRangeEnd = len;
             maximumCostPath = len;
             emit costsRangeEndChanged(m_costsRangeEnd);
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
     //    QList<qreal> moeoFitnessBestHistory;
    //   QList<qreal> moeoFitnessAverageHistory;
     if(index.column() < 2){
         if(index.row() > lengthHistory.size()-1){
             return  QVariant();
         }
         if (role == Qt::DisplayRole) {
             return lengthHistory[index.row()][index.column()];     //->at(index.column());
         } else if (role == Qt::EditRole) {
             return lengthHistory[index.row()][index.column()]; //->at(index.column());
         } else if (role == Qt::BackgroundRole) {
             foreach (QRect rect, m_mapping) {
                 if (rect.contains(index.column(), index.row()))
                     return QColor(m_mapping.key(rect));
             }
             // cell not mapped return white color
             return QColor(Qt::white);
         }
     }else{
         if(index.row() > costHistory.size()-1){
             return  QVariant();
         }
         if (role == Qt::DisplayRole) {
             return costHistory[index.row()][index.column()-2];     //->at(index.column());
         } else if (role == Qt::EditRole) {
             return costHistory[index.row()][index.column()-2]; //->at(index.column());
         } else if (role == Qt::BackgroundRole) {
             foreach (QRect rect, m_mapping) {
                 if (rect.contains(index.column()-2, index.row()))
                     return QColor(m_mapping.key(rect));
             }
             // cell not mapped return white color
             return QColor(Qt::white);
         }
     }


     return QVariant();
 }

 bool TspEvoSolverViewModel::setData(const QModelIndex &index, const QVariant &value, int role)
 {
     if (index.isValid() && role == Qt::EditRole) {
         lengthHistory[index.row()][index.column()] =  value.toDouble();
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



