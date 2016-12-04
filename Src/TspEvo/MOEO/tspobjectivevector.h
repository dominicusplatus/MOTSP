#ifndef TSPOBJECTIVEVECTOR_H
#define TSPOBJECTIVEVECTOR_H

#include <moeo>
#include <core/moeoRealObjectiveVector.h>
#include <tspdualobjectivevectortraits.h>

typedef moeoRealObjectiveVector<TspDualObjectiveVectorTraits> TSPObjectiveVector;

#endif // TSPOBJECTIVEVECTOR_H
