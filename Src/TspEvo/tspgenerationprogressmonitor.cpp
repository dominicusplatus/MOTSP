 #include <iostream>
 #include <fstream>
 #include <stdexcept>

#include <utils/eoStdoutMonitor.h>
#include <utils/compatibility.h>
#include <utils/eoParam.h>

#include "MOEO/tspdroute.h"
#include "tspgenerationprogressmonitor.h"
#include "tspdataservice.h"

using namespace std;

eoMonitor& TspGenerationProgressMonitor::operator()(void)
{
    int rinc =0;
    vector<TspDRoute*> routes;
    for(rinc =0; rinc< vec.size(); rinc++){
         routes.push_back((TspDRoute*)vec[rinc]);
    }
    TspRouteHistory.push_back(routes);

    /*
    for(iterator it = vec.begin(); it != vec.end(); ++it)
         {
            //cout << (*it)->longName() << delim;
       }
    */
   return *this;
}
