/*
   <moeoHC.h>
   Copyright (C) DOLPHIN Project-Team, INRIA Futurs, 2006-2008
   (C) OPAC Team, LIFL, 2002-2008

   Sébastien Cahon, Jean-Charles Boisson (Jean-Charles.Boisson@lifl.fr)
   François Legillon

   This software is governed by the CeCILL license under French law and
   abiding by the rules of distribution of free software.  You can  use,
   modify and/ or redistribute the software under the terms of the CeCILL
   license as circulated by CEA, CNRS and INRIA at the following URL
   "http://www.cecill.info".

   As a counterpart to the access to the source code and  rights to copy,
   modify and redistribute granted by the license, users are provided only
   with a limited warranty  and the software's author,  the holder of the
   economic rights,  and the successive licensors  have only  limited liability.

   In this respect, the user's attention is drawn to the risks associated
   with loading,  using,  modifying and/or developing or reproducing the
   software by the user in light of its specific status of free software,
   that may mean  that it is complicated to manipulate,  and  that  also
   therefore means  that it is reserved for developers  and  experienced
   professionals having in-depth computer knowledge. Users are therefore
   encouraged to load and test the software's suitability as regards their
   requirements in conditions enabling the security of their systems and/or
   data to be ensured and,  more generally, to use and operate it in the
   same conditions as regards security.
   The fact that you are presently reading this means that you have had
   knowledge of the CeCILL license and that you accept its terms.

   ParadisEO WebSite : http://paradiseo.gforge.inria.fr
Contact: paradiseo-help@lists.gforge.inria.fr
 */

#ifndef __moeoHC_h
#define __moeoHC_h
#include <scalarStuffs/explorer/moeoHCMoveLoopExpl.h>
#include <fitness/moeoSingleObjectivization.h>
#include <scalarStuffs/fitness/moeoIncrEvalSingleObjectivizer.h>
#include <scalarStuffs/algo/moeoSolAlgo.h>
#include <moHC.h>
//! Hill Climbing (HC)
/*!
  Class which describes the algorithm for a hill climbing.
  Adapts the moHC for a multi-objective problem using a moeoSingleObjectivization.
  M is for Move
 */
template <class M>
class moeoHC : public moeoSolAlgo < typename M::EOType >
{

	public:
		typedef typename M::EOType MOEOT;
		typedef typename MOEOT::ObjectiveVector ObjectiveVector;
		typedef typename MOEOT::Fitness Fitness;

		//! Full constructor.
		/*!
		  All the boxes are given in order the HC to use a moHCMoveLoopExpl.

		  \param _move_initializer a move initialiser.
		  \param _next_move_generator a neighborhood explorer.
		  \param _incremental_evaluation a (generally) efficient evaluation function.
		  \param _move_selection a move selector.
		  \param _singler a singleObjectivizer to translate objectiveVectors into fitness
		 */
		moeoHC (moMoveInit < M > & _move_initializer, moNextMove < M > & _next_move_generator,
				moMoveIncrEval < M,ObjectiveVector > & _incremental_evaluation, moMoveSelect < M > & _move_selection, moeoSingleObjectivization < MOEOT > & _singler) :
			incrEval((new moeoIncrEvalSingleObjectivizer<MOEOT,M>(_singler,_incremental_evaluation))),
			moveLoop(new moeoHCMoveLoopExpl<M>(_move_initializer,_next_move_generator,*(incrEval),_move_selection)),
			algo(*(moveLoop), (_singler))
	{}
		//! Function which launches the HC
		/*!
		  The HC has to improve a current solution.
		  As the moSA and the mo TS, it can be used for HYBRIDATION in an evolutionnary algorithm.

		  \param _solution a current solution to improve.
		  \return true.
		 */

		bool operator()(MOEOT &_solution){
			if (_solution.invalidObjectiveVector()) {
				(*incrEval)(_solution);
			}else{
			}
			return algo(_solution);
		}

	private:
		moeoIncrEvalSingleObjectivizer<MOEOT,M> *incrEval;
		moeoHCMoveLoopExpl<M> *moveLoop;
		//! the actual algo
		moHC<M> algo;

};
#endif
