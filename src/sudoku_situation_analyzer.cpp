/*
    This file is part of sudoku
    Copyright (C) 2008  Julien Thevenon ( julien_thevenon at yahoo.fr )

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>
*/
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
