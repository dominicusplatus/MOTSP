#include <tspdualeval.h>
#include "moroutegraph.h"


void TspDualEval::operator()(TspDRoute & route)
{
    TSPObjectiveVector objVector;
    objVector[0] = length(route);
    objVector[1] = cost(route);
    route.objectiveVector(objVector);
}


double TspDualEval::length(const TspDRoute & route)
{
    if (route.size () <= 0){
        return 0;
    }
    double totalDistance =0;
    for (unsigned i = 0 ; i < route.size () -1 ; i ++){
        int startVertex = route[i];
        int endVertex = route[i+1];
        double distance = MORouteGraph::distance(startVertex,endVertex);
        totalDistance += distance;
    }
    return totalDistance;
}


double TspDualEval::cost(const TspDRoute & route)
{
    if (route.size () <= 0){
        return 0;
    }
    double totalCost =0;
    for (unsigned i = 0 ; i < route.size () -1 ; i ++){
        int startVertex = route[i];
        int endVertex = route[i+1];
        double cost = MORouteGraph::cost(startVertex,endVertex);
        totalCost += cost;
    }
    return totalCost;
}

