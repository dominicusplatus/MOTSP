#ifndef TSPDROUTE_H
#define TSPDROUTE_H

#include "MOEO/tspobjectivevector.h"
/**
 *  Structure of the genotype for ZDT fonctions problem: a vector of double.
 */
class TspDRoute : public moeoRealVector < TSPObjectiveVector, double, double >
{

};

#endif // TSPDROUTE_H
