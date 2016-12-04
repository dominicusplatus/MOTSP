#include "MOEO/tspxoverdual.h"



void TspDualXover :: repair (TspDRoute & __route, unsigned __cut1, unsigned __cut2) {

    unsigned v [__route.size ()] ; // Number of times a cities are visited ...

      for (unsigned i = 0 ; i < __route.size () ; i ++)
        v [i] = 0 ;

      for (unsigned i = 0 ; i < __route.size () ; i ++)
        v [__route[i]] ++ ;

      std :: vector <unsigned> vert ;

      for (unsigned i = 0 ; i < __route.size () ; i ++)
        if (! v [i])
          vert.push_back (i) ;

      mix (vert) ;

      for (unsigned i = 0 ; i < __route.size () ; i ++)
        if (i < __cut1 || i >= __cut2)
          if (v [__route[i]] > 1) {
        __route [i] = vert.back () ;
        vert.pop_back () ;
      }
}


bool TspDualXover :: operator () (TspDRoute & __route1, TspDRoute & __route2) {

  unsigned cut1 = rng.random (__route1.size ()), cut2 = rng.random (__route2.size ()) ;

  if (cut2 < cut1)
    std :: swap (cut1, cut2) ;

  // Between the cuts
  for (unsigned i = cut1 ; i < cut2 ; i ++)
    std :: swap (__route1 [i], __route2 [i]) ;

  // Outside the cuts
  repair (__route1, cut1, cut2) ;
  repair (__route2, cut1, cut2) ;

  // Debug
  //assert (valid (__route1)) ;
  //assert (valid (__route2)) ;

  __route1.invalidate () ;
  __route2.invalidate () ;

  return true ;
}
