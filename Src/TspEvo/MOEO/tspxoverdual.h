#ifndef TSPXOVERDUAL_H
#define TSPXOVERDUAL_H

#include <assert.h>

#include <utils/eoRNG.h>

#include "partial_mapped_xover.h"
#include "route_valid.h"
#include "mix.h"

#include <eoOp.h>

#include "route.h"
#include "MOEO/tspdroute.h"

/** Partial Mapped Crossover */
class TspDualXover : public eoQuadOp <TspDRoute> {

public :

  bool operator () (TspDRoute & __route1, TspDRoute & __route2) ;

private :

  void repair (TspDRoute & __route, unsigned __cut1, unsigned __cut2) ;
} ;



#endif // TSPXOVERDUAL_H
