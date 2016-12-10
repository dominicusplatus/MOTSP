#ifndef TSPDUALOBJVECTORCOMPARATOR_H
#define TSPDUALOBJVECTORCOMPARATOR_H

#include "eoPop.h"
#include "comparator/moeoParetoObjectiveVectorComparator.h"
#include <utils/eoRNG.h>

template <class EOT>
class TspDualObjectiveVectorComparator
{
public:
    typedef typename EOT::ObjectiveVector ObjectiveVector;

    void operator() (eoPop <EOT> & pbest, const eoPop <EOT> & _pop, moeoParetoObjectiveVectorComparator<ObjectiveVector> & pareto)
    {
        for(int i =0; i< _pop.size(); i++)
        {
            if (pareto(pbest[i].objectiveVector(), _pop[i].objectiveVector()))
            {
                pbest[i]=_pop[i];
                pbest[i].objectiveVector(_pop[i].objectiveVector());
            }
            else if(! pareto(_pop[i].objectiveVector(), pbest[i].objectiveVector()))
            {
                int j = eo::rng.flip();

                if(j)
                {
                    pbest[i]=_pop[i];
                    pbest[i].objectiveVector(_pop[i].objectiveVector());
                }

            }

        }


    }




};

#endif // TSPDUALOBJVECTORCOMPARATOR_H
