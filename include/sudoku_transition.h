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
#ifndef SUDOKU_TRANSITION
#define SUDOKU_TRANSITION

#include "FSM_transition_if.h"

class sudoku_transition: public FSM_interfaces::FSM_transition_if
{
 public:
  // Constructors && Destructors
  sudoku_transition(unsigned int p_x,unsigned int p_y,unsigned int p_value);
  ~sudoku_transition(void);
  
  // Methods inherited from interface
  const std::string to_string(void)const;
  void to_string(std::string &)const;
  
  // Specific methods
  unsigned int getX(void)const;
  unsigned int getY(void)const;
  unsigned int getValue(void)const;

 private:
  unsigned int m_x;
  unsigned int m_y;
  unsigned int m_value;
};
#endif /* SUDOKU_TRANSITION */
