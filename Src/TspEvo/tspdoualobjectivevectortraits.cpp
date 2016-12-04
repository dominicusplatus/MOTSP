#include <tspdualobjectivevectortraits.h>


bool TspDualObjectiveVectorTraits::minimizing (int _i)
{
    // minimizing both
    return true;
}

bool TspDualObjectiveVectorTraits::maximizing (int _i)
{
    // minimizing both
    return false;
}

unsigned int TspDualObjectiveVectorTraits::nObjectives ()
{
    // 2 objectives
    return 2;
}
