#ifndef TSPDUALDATAHELPERS_H
#define TSPDUALDATAHELPERS_H



#include <utils/eoParser.h>
#include <utils/eoState.h>
#include <eoEvalFuncCounter.h>
#include "MOEO/tspdroute.h"
#include "tspdualeval.h"

#include "tspdualmutation.h"
#include "tspdualcrossover.h"
#include "tspdrouteinit.h"

#include "graph.h"

/*
 * This function creates an eoEvalFuncCounter<eoFlowShop> that can later be used to evaluate an individual.
 * @param eoParser& _parser  to get user parameters
 * @param eoState& _state  to store the memory
 */
eoEvalFuncCounter<TspDRoute> & do_make_eval(eoState& _state)
{
    /*
    // benchmark file name
    std::string benchmarkFileName = _parser.getORcreateParam(std::string(), "BenchmarkFile", "Benchmark file name (benchmarks are available at www.lifl.fr/~liefooga/benchmarks)", 'B',"Representation", true).value();
    if (benchmarkFileName == "") {
        std::string stmp = "*** Missing name of the benchmark file\n";
        stmp += "    Type '-B=the_benchmark_file_name' or '--BenchmarkFile=the_benchmark_file_name'\n";
        stmp += "    Benchmarks files are available at www.lifl.fr/~liefooga/benchmarks";
        throw std::runtime_error(stmp.c_str());
    }
    // reading of the parameters contained in the benchmark file
    FlowShopBenchmarkParser fParser(benchmarkFileName);
    */

    unsigned int M = 0;//fParser.getM();
    unsigned int N =0;// fParser.getN();

    std::vector< std::vector<unsigned int> > p;// = fParser.getP();
    std::vector<unsigned int> d;// = fParser.getD();

    // build of the initializer (a pointer, stored in the eoState)
    TspDualEval* plainEval = new TspDualEval;//(M, N, p, d);
    // turn that object into an evaluation counter
    eoEvalFuncCounter<TspDRoute>* eval = new eoEvalFuncCounter<TspDRoute> (* plainEval);
    // store in state
    _state.storeFunctor(eval);
    // and return a reference
    return *eval;
}




/*
 * This function builds the operators that will be applied to the eoFlowShop
 * @param eoParameterLoader& _parser to get user parameters
 * @param eoState& _state to store the memory
 */
eoGenOp<TspDRoute> & do_make_op( eoState& _state)
{

    /////////////////////////////
    // Variation operators
    ////////////////////////////

    // the crossover
    ////////////////

    // a first crossover
    eoQuadOp<TspDRoute> *cross = new TspDualCrossoverQuad;
    // store in the state
    _state.storeFunctor(cross);

    // relative rate in the combination
    double cross1Rate = 0;//_parser.createParam(1.0, "crossRate", "Relative rate for the only crossover", 0, "Variation Operators").value();
    // creation of the combined operator with this one
    eoPropCombinedQuadOp<TspDRoute> *propXover = new eoPropCombinedQuadOp<TspDRoute>(*cross, cross1Rate);
    // store in the state
    _state.storeFunctor(propXover);


    // the mutation
    ///////////////

    // a first mutation : the shift mutation
    eoMonOp<TspDRoute> *mut = new TspDualMutation;
    _state.storeFunctor(mut);
    // its relative rate in the combination
    double mut1Rate = 0;//_parser.createParam(0.5, "shiftMutRate", "Relative rate for shift mutation", 0, "Variation Operators").value();
    // creation of the combined operator with this one
    eoPropCombinedMonOp<TspDRoute> *propMutation = new eoPropCombinedMonOp<TspDRoute>(*mut, mut1Rate);
    _state.storeFunctor(propMutation);

    // end of crossover and mutation definitions
    ////////////////////////////////////////////

    // the crossover - with probability pCross
    eoProportionalOp<TspDRoute> * propOp = new eoProportionalOp<TspDRoute> ;
    _state.storeFunctor(propOp);
    eoQuadOp<TspDRoute> *ptQuad = new eoQuadCloneOp<TspDRoute>;
    _state.storeFunctor(ptQuad);
  //  propOp -> add(*propXover, pCrossParam.value()); // crossover, with proba pcross
//    propOp -> add(*ptQuad, 1-pCrossParam.value()); // nothing, with proba 1-pcross

    // now the sequential
    eoSequentialOp<TspDRoute> *op = new eoSequentialOp<TspDRoute>;
    _state.storeFunctor(op);
    op -> add(*propOp, 1.0);	 // always do combined crossover
 //   op -> add(*propMutation, pMutParam.value()); // then mutation, with proba pmut

    // return a reference
    return *op;
}



/*
 * This function creates an eoInit<eoFlowShop> that can later be used to initialize the population (see make_pop.h).
 * @param eoParser& _parser  to get user parameters
 * @param eoState& _state  to store the memory
 */
eoInit<TspDRoute> & do_make_genotype(eoState& _state)
{
    /*
    // benchmark file name
    std::string benchmarkFileName = _parser.getORcreateParam(std::string(), "BenchmarkFile", "Benchmark file name (benchmarks are available at www.lifl.fr/~liefooga/benchmarks/)", 'B',"Representation", true).value();
    if (benchmarkFileName == "") {
        std::string stmp = "*** Missing name of the benchmark file\n";
        stmp += "   Type '-B=the_benchmark_file_name' or '--BenchmarkFile=the_benchmark_file_name'\n";
        stmp += "   Benchmarks files are available at www.lifl.fr/~liefooga/benchmarks";
        throw std::runtime_error(stmp.c_str());
    }
    // reading of number of jobs to schedule contained in the benchmark file
    FlowShopBenchmarkParser fParser(benchmarkFileName);
    */

    //      MORouteGraph
   //    unsigned int N = MORouteGraph::size();          //fParser.getN();
    // build of the initializer (a pointer, stored in the eoState)
    eoInit<TspDRoute>* init = new TspDRouteInit;
    // store in state
    _state.storeFunctor(init);
    // and return a reference
    return *init;
}






#endif // TSPDUALDATAHELPERS_H
