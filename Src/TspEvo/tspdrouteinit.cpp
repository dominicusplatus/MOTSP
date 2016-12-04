
#include "tspdrouteinit.h"
#include "moroutegraph.h"

#include <utils/eoRNG.h>

#include "route_init.h"
#include "graph.h"

void TspDRouteInit :: operator () (TspDRoute & __route) {

  // Init.
  __route.clear () ;
  //load the vertexes from pre-loaded graph - indexes are unsorted at beggning
    for (unsigned i = 0 ; i < MORouteGraph :: size () ; i ++){
       //  std::pair <double, double> coords = MORouteGraph::getCityCoords(i);
        __route.push_back(i);
    }

  // Swap. cities

  for (unsigned i = 0 ; i < MORouteGraph :: size () ; i ++) {
    unsigned j = (unsigned) (MORouteGraph :: size () * (rand () / (RAND_MAX + 1.0))) ;
    unsigned city = __route [i] ;
    __route [i] = __route [j] ;
    __route [j] = city ;
  }
}
