#include "tspdataservice.h"

/*
TspDataService::TspDataService()    //(QObject *parent) : QObject(parent)
{

}

 eoPop <Route> TspDataService::getPopulation()
{
    return TspDataService::m_population;
}

*/


 std::vector<std::vector <TspDRoute*>> TspRouteHistory;
 std::vector<eoPop <TspDRoute>> TspRoutePopulationsHistory;
  eoPop <TspDRoute> TspRoutes;
  QList<TspDRoute> BestTspRoutes;

