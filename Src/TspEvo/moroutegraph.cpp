#include "moroutegraph.h"

#include <fstream>
#include <iostream>
#include <math.h>

#include "moroutegraph.h"

namespace MORouteGraph {

  static std :: vector <std :: pair <double, double> > vectCoord ; // Coordinates

  static std :: vector <std :: vector <double> > dist ; // Distances Mat.
  static std :: vector <std :: vector <double> > costs ; // Costs Mat.


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


  void computeDistances2 () {

    // Dim.
    unsigned numCities = vectCoord.size () ;
    dist.resize (numCities) ;
    for (unsigned i = 0 ; i < dist.size () ; i ++)
      dist [i].resize (numCities) ;

    // Computations.
    for (unsigned i = 0 ; i < dist.size () ; i ++)
      for (unsigned j = i + 1 ; j < dist.size () ; j ++) {
        double distX =  abs( vectCoord [i].first - vectCoord [j].first) ;
        double distY =  abs(vectCoord [i].second - vectCoord [j].second) ;
        double len =  (sqrt (distX * distX + distY * distY));
        dist [i] [j] = dist [j] [i] =  len;
      }
  }


  void computeCosts()
  {
      unsigned numCities = vectCoord.size () ;
      costs.resize (numCities) ;
      for (unsigned i = 0 ; i < costs.size () ; i ++)
        costs [i].resize (numCities) ;

      for (unsigned i = 0 ; i < costs.size () ; i ++)
        for (unsigned j = i + 1 ; j < costs.size () ; j ++) {
            double distX =  ( vectCoord [i].first - vectCoord [j].first) ;
            double distY =  (vectCoord [i].second - vectCoord [j].second) ;
          int vertexDiff = abs(j-i);
          unsigned len =  (unsigned) (sqrt ((float) (distX * distX + distY * distY)) + 0.5) ;
          unsigned cost =(unsigned) (len * 1/numCities * vertexDiff) ;
          costs [i] [j] = dist [j] [i] = cost;
        }
  }

  void computeCosts2()
  {
      unsigned numCities = vectCoord.size () ;
      costs.resize (numCities) ;
      for (unsigned i = 0 ; i < costs.size () ; i ++)
        costs [i].resize (numCities) ;

      for (unsigned i = 0 ; i < costs.size () ; i ++)
        for (unsigned j = i + 1 ; j < costs.size () ; j ++) {
            double distX = abs ( vectCoord [i].first - vectCoord [j].first) ;
            double distY = abs (vectCoord [i].second - vectCoord [j].second) ;
          int vertexDiff = abs(j-i);
           double len =  (sqrt (distX * distX + distY * distY));
          double cost = len * 1/numCities * vertexDiff;
          unsigned int costi =  len * (1/(numCities)*(j-i)) +1 ;
          costs [i] [j] = dist [j] [i] = costi;
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
        f >> vectCoord [i].first >> vectCoord [i].second;   //>> vectCoordTmp.first;
        //vertcost[i] = vectCoordTmp.first;
    }
      f.close () ;

      computeDistances2 () ;
      computeCosts2();

    }
    else {

      std :: cout << __fileName << " doesn't exist !!!" << std :: endl ;
      // Bye !!!
    }
  }

  double distance (unsigned __from, unsigned __to) {

    return dist [__from] [__to] ;
  }

 double cost(unsigned __from, unsigned __to) {

    return costs [__from] [__to] ;
  }

 std::pair <double, double> getCityCoords(unsigned city)
{
    return vectCoord[city];
}

}
