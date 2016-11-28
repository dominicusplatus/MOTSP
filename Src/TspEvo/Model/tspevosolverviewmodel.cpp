#include "tspevosolverviewmodel.h"
#include "tspevofitnesshistorydatamodel.h"
#include <QtCore/QVector>
#include <QtCore/QTime>
#include <QtCore/QRect>
#include <QtGui/QColor>

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
    m_population = pop;

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

     emit populationChanged(m_population);

       QModelIndex indexA = this->index(0, 0, QModelIndex());
       QModelIndex indexC = this->index(m_populationsize, 1, QModelIndex());

       UpdateDataRange();

      // QModelIndex iend = QModelIndex(0,0);
       emit dataChanged(indexA, indexC);


       //emit historyModelChanged(m_historyModel);

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



