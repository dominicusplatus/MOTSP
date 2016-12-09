#ifndef TSPEVAL_H
#define TSPEVAL_H


#include <eoEasyEA.h>
#include <eoGenContinue.h>
#include <eoStochTournamentSelect.h>
#include <eoSGATransform.h>
#include <eoSelectNumber.h>

#include <moeo>
#include "MOEO/tspobjectivevector.h"
#include "MOEO/tspdroute.h"

/**
 * abstract class of ZDT evaluation fonctions
 */
class TspEval : public moeoEvalFunc <TspDRoute>
{
public:

    /**
     * operator evaluate genotype
     */
    void operator () (TspDRoute & _element);

private:

    /**
     * first fonction to minimize
     * @param _element the genotype
     */
    virtual double evalF(TspDRoute & _element)=0;

    /**
     * first intermediate calculation for the second fonction to minimize
     * @param _element the genotype
     */
    virtual double evalG(TspDRoute & _element)=0;

    /**
     * second intermediate calculation for the second fonction to minimize
     * @param _f result of evalF
     * @param _g result of evalG
     */
    virtual double evalH(double _f, double _g)=0;

};

class TspBaseEval : public TspEval
{

private:

    /**
     * first fonction to minimize
     * @param _element the genotype
     */
    double evalF(TspDRoute & _element);

    /**
     * first intermediate calculation for the second fonction to minimize
     * @param _element the genotype
     */
    double evalG(TspDRoute & _element);

    /**
     * second intermediate calculation for the second fonction to minimize
     * @param _f result of evalF
     * @param _g result of evalG
     */
    double evalH(double _f, double _g);

};


#endif // TSPEVAL_H
