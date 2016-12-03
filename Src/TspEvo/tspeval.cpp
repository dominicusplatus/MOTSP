#include "tspeval.h"

double TspBaseEval::evalF(TspDRoute & _element)
{
    return _element[0];
}

double TspBaseEval::evalG(TspDRoute & _element)
{
    unsigned int n=_element.size();
    double res=0.0;
    for (unsigned int i=1; i<n; i++)
        res+=_element[i];
    res = 1.0 + 9.0 * res / (n-1);

    return res;
}

double TspBaseEval::evalH(double _f, double _g)
{
    return 1.0 - sqrt(_f/_g);
}

void TspEval::operator() (TspDRoute & _element)
{
    if (_element.invalidObjectiveVector()) {
        unsigned int nbVar=_element.size();
        double f1 = evalF(_element);
        double g = evalG(_element);
        double h = evalH(f1, g);
        double f2 = g * h;


        TSPObjectiveVector objVec(nbVar);

        objVec[0]= f1;
        objVec[1]= f2;

        _element.objectiveVector(objVec);
    }
}
