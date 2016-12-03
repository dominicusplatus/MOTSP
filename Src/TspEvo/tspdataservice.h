#ifndef TSPDATASERVICE_H
#define TSPDATASERVICE_H

#include <QObject>

#include <QObject>
#include "QVector"
#include <QtCore/QAbstractTableModel>
#include <QtCore/QHash>
#include <QtCore/QRect>

#include <eoEasyEA.h>
#include <eoGenContinue.h>
#include <eoStochTournamentSelect.h>
#include <eoSGATransform.h>
#include <eoSelectNumber.h>
#include <moeo>

#include "graph.h"
#include "route.h"
#include "route_init.h"
#include "route_eval.h"
#include "order_xover.h"
#include "partial_mapped_xover.h"
#include "city_swap.h"
#include <utils/checkpointing>
#include <eoOp.h> // for eoInit
#include <eoPersistent.h>
#include <eoInit.h>
#include <utils/rnd_generators.h>  // for shuffle method

extern std::vector<eoPop <Route>> TspRouteHistory;
extern  eoPop <Route> TspRoutes;
extern  QList<Route> BestTspRoutes;


class TspDataService    //: public QObject
{

public:
     static eoPop <Route> getPopulation();
    //   explicit TspDataService(QObject *parent = 0);
    static eoPop <Route> m_population;

private:

};

#endif // TSPDATASERVICE_H
