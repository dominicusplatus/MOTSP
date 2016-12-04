#ifndef MOROUTEGRAPH_H
#define MOROUTEGRAPH_H


#include <vector>
#include <utility>


#include <fstream>
#include <iostream>
#include <math.h>

namespace MORouteGraph {

  void load (const char * __file_name) ;
  /* Loading cities
     (expressed by their coordinates)
     from the given file name */

  float distance (unsigned __from, unsigned __to) ;
  float cost(unsigned __from, unsigned __to);
  std::pair <double, double> getCityCoords(unsigned city);
   unsigned size () ; // How many cities ?
}


#endif // MOROUTEGRAPH_H
