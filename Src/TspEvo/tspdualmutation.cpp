#include <tspdualmutation.h>


std::string TspDualMutation::className() const
{
    return "FlowShopOpMutationExchange";
}


bool TspDualMutation::operator()(TspDRoute & _flowshop)
{
    bool isModified;
    TspDRoute result = _flowshop;
    // computation of the 2 random points
    unsigned int point1, point2;
    do
    {
        point1 = rng.random(result.size());
        point2 = rng.random(result.size());
    } while (point1 == point2);
    // swap
    std::swap (result[point1], result[point2]);
    // update (if necessary)
    if (result != _flowshop)
    {
        // update
        _flowshop.value(result);
        // the genotype has been modified
        isModified = true;
    }
    else
    {
        // the genotype has not been modified
        isModified = false;
    }
    // return 'true' if the genotype has been modified
    return isModified;
}
