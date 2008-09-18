#include "sudoku_situation_analyzer.h"

//-----------------------------------------------------------------------------
sudoku_situation_analyzer::sudoku_situation_analyzer
(
 const unsigned int p_side_size
 ):
  FSM_situation_analyzer<sudoku_situation,sudoku_transition>(),
  m_big_side_size( p_side_size* p_side_size)
{
}

//-----------------------------------------------------------------------------
sudoku_situation_analyzer::~sudoku_situation_analyzer(void)
{
}

//-----------------------------------------------------------------------------
string sudoku_situation_analyzer::toString(void)
{
  return "sudoku_situation_analyzer";
}

//-----------------------------------------------------------------------------
vector<sudoku_transition*> sudoku_situation_analyzer::getTransitions
(
 sudoku_situation* p_situation
 )
{
  vector<sudoku_transition*> l_transitions;
  for(unsigned int l_x=0;l_x<m_big_side_size; l_x++)
    {
      for(unsigned int l_y=0;l_y<m_big_side_size; l_y++)
	{
	  if(!p_situation->getValue(l_x,l_y))
	    {
	      set<unsigned int> l_authorized_values;
	      size_t l_previous_size = l_transitions.size();
	      p_situation->getContext()->getAuthorizedValues(l_x,l_y,l_authorized_values);
	      set<unsigned int>::const_iterator l_iter = l_authorized_values.begin();
	      set<unsigned int>::const_iterator l_iter_end = l_authorized_values.end();
	      while(l_iter != l_iter_end)
		{
		  l_transitions.push_back(new sudoku_transition(l_x,l_y,*l_iter));
		  ++l_iter;
		}
	      if(l_previous_size == l_transitions.size())
		{
		  cout << "You miss something : no value possible for (" << l_x << "," << l_y << ")" << endl ;
		  p_situation->setInvalid();
		}
	    }
	}
    }
  return l_transitions;
}
