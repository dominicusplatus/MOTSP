#ifndef TSPDUALCROSSOVER_H
#define TSPDUALCROSSOVER_H

#include <eoOp.h>
#include <MOEO/tspdroute.h>

/**
 * Quadratic crossover operator for flow-shop (modify the both genotypes)
 */
class TspDualCrossoverQuad : public eoQuadOp < TspDRoute >
{
public:

    /**
     * the class name (used to display statistics)
     */
    std::string className() const;


    /**
     * eoQuad crossover - _flowshop1 and _flowshop2 are the (future) offspring, i.e. _copies_ of the parents
     * @param _flowshop1 the first parent
     * @param _flowshop2 the second parent
     */
    bool operator()(TspDRoute & _flowshop1, TspDRoute & _flowshop2);


private:

    /**
     * generation of an offspring by a 2 points crossover
     * @param _parent1 the first parent
     * @param _parent2 the second parent
     * @param _point1 the first point
     * @param _point2 the second point
     */
    TspDRoute generateOffspring(const TspDRoute & _parent1, const TspDRoute & _parent2, unsigned int _point1, unsigned int _point2);

};

#endif // TSPDUALCROSSOVER_H
