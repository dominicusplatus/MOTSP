#ifndef TSPDROUTEINIT_H
#define TSPDROUTEINIT_H

#include <eoInit.h>

#include "route.h"
#include "MOEO/tspobjectivevector.h"
#include "MOEO/tspdroute.h"

class TspDRouteInit : public eoInit <TspDRoute> {

public :

  void operator () (TspDRoute & __route) ;

} ;

#endif // TSPDROUTEINIT_H
