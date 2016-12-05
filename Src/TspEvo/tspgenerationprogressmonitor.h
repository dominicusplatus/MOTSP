#ifndef TSPGENERATIONPROGRESSMONITOR_H
#define TSPGENERATIONPROGRESSMONITOR_H

#include "EO.h"
#include <string>
#include <iostream>

#include <utils/eoMonitor.h>
#include <utils/eoLogger.h>
#include <eoObject.h>


class TspGenerationProgressMonitor : public eoMonitor
{
    public:
        eoMonitor& operator()(void);
};

#endif // TSPGENERATIONPROGRESSMONITOR_H
