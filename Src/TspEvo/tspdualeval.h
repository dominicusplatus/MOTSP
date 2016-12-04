#ifndef TSPDUALEVAL_H
#define TSPDUALEVAL_H

#include <vector>
#include <core/moeoEvalFunc.h>
#include <MOEO/tspdroute.h>

/**
 * Evaluation of the objective vector a (multi-objective)  object
 */
class TspDualEval : public moeoEvalFunc<TspDRoute>
{
public:

    void operator()(TspDRoute & route);


private:

    double length(const TspDRoute & route);

    double cost(const TspDRoute & route);


};


#endif // TSPDUALEVAL_H
