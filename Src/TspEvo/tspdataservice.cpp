#include "tspdataservice.h"
#include "moroutegraph.h"
#include "tspdualeval.h"

 std::vector<std::vector <TspDRoute*>> TspRouteHistory;
 std::vector<eoPop <TspDRoute>> TspRoutePopulationsHistory;

  std::vector<std::vector<qreal>> lengthHistory;
  std::vector<std::vector<qreal>> costHistory;
  eoPop <TspDRoute> TspRoutes;
  QList<TspDRoute> BestTspRoutes;
    qreal minimumCostPath;
    qreal maximumCostPath;

    qreal minimumCostLength;
    qreal maximumCostLength;

     int tspGenerations;
     int tspPopSize;

    void DesignateParetoFrontSolutionsForPopulation(int limit,eoPop <TspDRoute> pop)
    {
        BestTspRoutes.clear();

        int result = 0;
         TspDRoute best;

        //get first route
        if(pop.size() < 1){
            return;
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

        BestTspRoutes.push_back(best);

    }
