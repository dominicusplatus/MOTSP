#ifndef TSPXOVERDUAL_H
#define TSPXOVERDUAL_H

#include <assert.h>

#include <utils/eoRNG.h>

#include "partial_mapped_xover.h"
#include "route_valid.h"
#include "mix.h"

#include <eoOp.h>

#include "route.h"

/** Partial Mapped Crossover */
class TspDualXover : public eoQuadOp <Route> {

public :

  bool operator () (Route & __route1, Route & __route2) ;

private :

  void repair (Route & __route, unsigned __cut1, unsigned __cut2) ;
} ;



#endif // TSPXOVERDUAL_H
