#include "sudoku.h"
#include "sudoku_motor.h"
#include "sudoku_situation_analyzer.h"

#include <iostream>
using namespace std;

//-----------------------------------------------------------------------------
sudoku::sudoku(void):FSM<sudoku_situation,sudoku_transition>("sudoku",new sudoku_motor(), new sudoku_situation_analyzer(3))
{
	setSituation(new sudoku_situation(3));

	//Facile
/*	getSituation()->setValue(0,2,8);
	getSituation()->setValue(0,5,2);
	getSituation()->setValue(0,6,5);
	getSituation()->setValue(0,7,7);
	getSituation()->setValue(1,1,4);
	getSituation()->setValue(1,2,5);
	getSituation()->setValue(1,4,7);
	getSituation()->setValue(1,5,8);
	getSituation()->setValue(1,8,6);
	getSituation()->setValue(2,3,4);
	getSituation()->setValue(2,4,9);
	getSituation()->setValue(2,5,5);
	getSituation()->setValue(2,6,1);
	getSituation()->setValue(2,7,3);
	getSituation()->setValue(3,0,8);
	getSituation()->setValue(3,2,7);
	getSituation()->setValue(3,7,6);
	getSituation()->setValue(5,1,2);
	getSituation()->setValue(5,6,7);
	getSituation()->setValue(5,8,1);
	getSituation()->setValue(6,1,8);
	getSituation()->setValue(6,2,2);
	getSituation()->setValue(6,3,5);
	getSituation()->setValue(6,4,3);
	getSituation()->setValue(6,5,7);
	getSituation()->setValue(7,0,7);
	getSituation()->setValue(7,3,9);
	getSituation()->setValue(7,4,2);
	getSituation()->setValue(7,6,8);
	getSituation()->setValue(7,7,5);
	getSituation()->setValue(8,1,5);
	getSituation()->setValue(8,2,3);
	getSituation()->setValue(8,3,1);
	getSituation()->setValue(8,6,6);
*/


	//Complete to help facile
	//	getSituation()->setValue(0,0,3);
	//	getSituation()->setValue(0,1,9);
	//	getSituation()->setValue(0,3,6);
	//	getSituation()->setValue(0,4,1);
	//	getSituation()->setValue(0,8,4);

	//	getSituation()->setValue(1,0,1);
	//	getSituation()->setValue(1,3,3);
	//	getSituation()->setValue(1,6,2);
	//	getSituation()->setValue(1,7,9);

	//	getSituation()->setValue(2,0,2);
	//	getSituation()->setValue(2,1,7);
	//	getSituation()->setValue(2,2,6);
	//	getSituation()->setValue(2,8,8);


	//	getSituation()->setValue(3,1,3);
	//	getSituation()->setValue(3,3,2);
	//	getSituation()->setValue(3,4,4);
	//	getSituation()->setValue(3,5,1);
	//	getSituation()->setValue(3,6,9);
	//	getSituation()->setValue(3,8,5);

	//	getSituation()->setValue(5,0,5);
	//	getSituation()->setValue(5,2,9);
	//	getSituation()->setValue(5,3,8);
	//	getSituation()->setValue(5,4,6);
	//	getSituation()->setValue(5,5,3);
	//	getSituation()->setValue(5,7,4);

	//	getSituation()->setValue(6,0,6);
	//	getSituation()->setValue(6,6,4);
	//	getSituation()->setValue(6,7,1);
	//	getSituation()->setValue(6,8,9);

	//	getSituation()->setValue(7,1,1);
	//	getSituation()->setValue(7,2,4);
	//	getSituation()->setValue(7,5,6);
	//	getSituation()->setValue(7,8,3);

	//	getSituation()->setValue(8,0,9);
	//	getSituation()->setValue(8,4,8);
	//	getSituation()->setValue(8,5,4);
	//	getSituation()->setValue(8,7,2);
	//	getSituation()->setValue(8,8,7);



	//Moyen
/*	getSituation()->setValue(0,0,3);
	getSituation()->setValue(4,0,5);
	getSituation()->setValue(6,0,7);

	getSituation()->setValue(0,1,7);
	getSituation()->setValue(2,1,8);
	getSituation()->setValue(3,1,9);
	getSituation()->setValue(7,1,1);
	getSituation()->setValue(8,1,2);

	getSituation()->setValue(5,2,4);

	getSituation()->setValue(0,3,5);
	getSituation()->setValue(5,3,9);
	getSituation()->setValue(6,3,6);

	getSituation()->setValue(1,4,3);
	getSituation()->setValue(2,4,4);
	getSituation()->setValue(6,4,2);
	getSituation()->setValue(7,4,9);

	getSituation()->setValue(2,5,7);
	getSituation()->setValue(3,5,6);
	getSituation()->setValue(8,5,4);

	getSituation()->setValue(3,6,2);

	getSituation()->setValue(0,7,9);
	getSituation()->setValue(1,7,6);
	getSituation()->setValue(5,7,7);
	getSituation()->setValue(6,7,5);
	getSituation()->setValue(8,7,1);

	getSituation()->setValue(2,8,1);
	getSituation()->setValue(4,8,9);
	getSituation()->setValue(8,8,7);*/

	// Diabolique
	getSituation()->setValue(0,0,3);
	getSituation()->setValue(5,0,1);
	getSituation()->setValue(6,0,2);

	getSituation()->setValue(2,1,4);
	getSituation()->setValue(4,1,8);
	getSituation()->setValue(6,1,5);

	getSituation()->setValue(0,2,1);
	getSituation()->setValue(2,2,6);
	getSituation()->setValue(4,2,7);

	getSituation()->setValue(4,3,3);
	getSituation()->setValue(5,3,5);
	getSituation()->setValue(6,3,4);
	getSituation()->setValue(8,3,6);

	getSituation()->setValue(3,4,9);
	getSituation()->setValue(6,4,3);

	getSituation()->setValue(5,5,6);
	getSituation()->setValue(7,5,5);

	getSituation()->setValue(0,6,9);
	getSituation()->setValue(5,6,8);
	getSituation()->setValue(8,6,3);

	getSituation()->setValue(0,7,5);
	getSituation()->setValue(2,7,3);
	getSituation()->setValue(8,7,4);

	getSituation()->setValue(2,8,1);
	getSituation()->setValue(5,8,2);
	getSituation()->setValue(6,8,6);


}

//-----------------------------------------------------------------------------
sudoku::~sudoku(void)
{
}

//-----------------------------------------------------------------------------
void sudoku::configure(void)
{
}

//-----------------------------------------------------------------------------
string sudoku::toString(void)const
{
	string l_result = "__FUNCTION__ Not implemented";
	return l_result;
}

//-----------------------------------------------------------------------------
FSM_if* createGameOfLife()
{
	return new sudoku();
}


//-----------------------------------------------------------------------------
void sudoku::computeTransitionWeights(std::vector<FSM_weighted_transition_index_if*> &p_vector)const
{
  cout << " sudoku implementation of " << __FUNCTION__ << endl ;

  sudoku_context *l_context = getSituation()->getContext();
  assert(l_context);
  unsigned int l_nb_transition = l_context->getNbTransitions();
  map<pair<unsigned int,unsigned int>,unsigned int> l_pair_counter;

  // Counting number of transition per coordinnate
  for(unsigned int l_index=0; l_index<l_nb_transition; l_index++)
    {
      sudoku_transition* l_transition = l_context->getSpecificTransition(l_index);
      assert(l_transition);
      pair<unsigned int,unsigned int> l_pair(l_transition->getX(),l_transition->getY());
      map<pair<unsigned int,unsigned int>,unsigned int>::iterator l_iter = l_pair_counter.find(l_pair);
      if(l_iter != l_pair_counter.end())
	{
	  l_iter->second++;
	}
      else
	{
	  l_iter = l_pair_counter.insert(map<pair<unsigned int,unsigned int>,unsigned int>::value_type(l_pair,1)).first;
	}
    }
  
  // Creating weighted transition index
  for(unsigned int l_index=0; l_index<l_nb_transition; l_index++)
    {
      sudoku_transition* l_transition = l_context->getSpecificTransition(l_index);
      assert(l_transition);
      pair<unsigned int,unsigned int> l_pair(l_transition->getX(),l_transition->getY());
      map<pair<unsigned int,unsigned int>,unsigned int>::iterator l_iter = l_pair_counter.find(l_pair);
      assert(l_iter != l_pair_counter.end());
      unsigned int l_weight = l_iter->second;

      if(l_weight > 1 )
	{
	  unsigned char l_count_line = 0;
	  unsigned char l_count_column = 0;
	  unsigned char l_count_square = 0;
	  unsigned int l_square_x = l_transition->getX() / 3;
	  unsigned int l_square_y = l_transition->getY() / 3;
	  for(unsigned int l_index2=0;l_index2<9;l_index2++)
	    {
	      set<unsigned int> l_result ;
	      if(!getSituation()->getValue(l_index2,l_transition->getY()))
		{
		  l_context->getAuthorizedValues(l_index2,l_transition->getY(),l_result);
		  if(l_result.count(l_transition->getValue()))
		    {
		      l_count_line++;
		    }
		  l_result.clear();
		}
	      if(!getSituation()->getValue(l_transition->getX(),l_index2))
		{
		  l_context->getAuthorizedValues(l_transition->getX(),l_index2,l_result);
		  if(l_result.count(l_transition->getValue()))
		    {
		      l_count_column++;
		    }
		  l_result.clear();
		}
	      if(!getSituation()->getValue(3*l_square_x+l_index2 /3 ,3*l_square_y + (l_index2 % 3 )))
		{
		  l_context->getAuthorizedValues(3*l_square_x+l_index2 /3 ,3*l_square_y + (l_index2 % 3 ),l_result);
		  if(l_result.count(l_transition->getValue()))
		    {
		      l_count_square++;
		    }
	      
		}
	    }
	      if(l_count_line == 1 || l_count_square == 1 || l_count_column == 1)
		{
		  cout << l_transition->toString() << " weight is forced to 1 " << endl ;
		  l_weight = 1;
		}
	}
      
      p_vector.push_back(new FSM_weighted_transition_index(l_index,l_weight));
    }

}

//-----------------------------------------------------------------------------
extern "C"
{
	void registerFsm(map<string,FSM_creator> *p_factory)
	{
		registerFsm("sudoku",createGameOfLife,p_factory);
	}
}
