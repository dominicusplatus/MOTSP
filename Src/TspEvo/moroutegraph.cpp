#include "moroutegraph.h"

#include <fstream>
#include <iostream>
#include <math.h>

#include "graph.h"

namespace MORouteGraph {

  static std :: vector <std :: pair <double, double> > vectCoord ; // Coordinates

  static std :: vector <std :: vector <unsigned> > dist ; // Distances Mat.
  static std :: vector <double>  costs; // Costs Mat.

  unsigned size () {

    return dist.size () ;
  }

  void computeDistances () {

    // Dim.
    unsigned numCities = vectCoord.size () ;
    dist.resize (numCities) ;
    for (unsigned i = 0 ; i < dist.size () ; i ++)
      dist [i].resize (numCities) ;

    // Computations.
    for (unsigned i = 0 ; i < dist.size () ; i ++)
      for (unsigned j = i + 1 ; j < dist.size () ; j ++) {
        double distX = vectCoord [i].first - vectCoord [j].first ;
        double distY = vectCoord [i].second - vectCoord [j].second ;
        dist [i] [j] = dist [j] [i] = (unsigned) (sqrt ((float) (distX * distX + distY * distY)) + 0.5) ;
      }
  }

  void computeCosts()
  {
        //TODO
      unsigned numCities = vectCoord.size () ;
      dist.resize (numCities) ;
      for (unsigned i = 0 ; i < dist.size () ; i ++)
        dist [i].resize (numCities) ;

      // Computations.
      for (unsigned i = 0 ; i < dist.size () ; i ++)
        for (unsigned j = i + 1 ; j < dist.size () ; j ++) {
          double distX = vectCoord [i].first - vectCoord [j].first ;
          double distY = vectCoord [i].second - vectCoord [j].second ;
          dist [i] [j] = dist [j] [i] = (unsigned) (sqrt ((float) (distX * distX + distY * distY)) + 0.5) ;
        }
  }

  void load (const char * __fileName) {

    std :: ifstream f (__fileName) ;

    std :: cout << ">> Loading [" << __fileName << "]" << std :: endl ;

    if (f) {

      unsigned num_vert ;

      f >> num_vert ;
      vectCoord.resize (num_vert) ;
    costs.resize(num_vert);

      for (unsigned i = 0 ; i < num_vert ; i ++)
    {
        std::pair <double, double>  vectCoordTmp;
        f >> vectCoord [i].first >> vectCoord [i].second >> vectCoordTmp.first;
        costs[i] = vectCoordTmp.first;
    }
      f.close () ;

      computeDistances () ;
      computeCosts();

    }
    else {

      std :: cout << __fileName << " doesn't exist !!!" << std :: endl ;
      // Bye !!!
    }
  }

  float distance (unsigned __from, unsigned __to) {

    return dist [__from] [__to] ;
  }

 float cost(unsigned __from, unsigned __to) {

    return dist [__from] [__to] ;
  }

 std::pair <double, double> getCityCoords(unsigned city)
{
    return vectCoord[city];
}

}
