#ifndef TSPDUALMUTATION_H
#define TSPDUALMUTATION_H

#include <eoOp.h>
#include <MOEO/tspdroute.h>

/**
 * Exchange mutation operator for the flow-shop
 */
class TspDualMutation : public eoMonOp<TspDRoute>
{
public:

    /**
     * the class name (used to display statistics)
     */
    std::string className() const;


    /**
     * modifies the parent with an exchange mutation
     * @param _flowshop the parent genotype (will be modified)
     */
    bool operator()(TspDRoute & _flowshop);

};

#endif // TSPDUALMUTATION_H
