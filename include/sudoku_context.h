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

#ifndef SUDOKU_CONTEXT_H
#define SUDOKU_CONTEXT_H

#include "FSM_context.h"
#include "sudoku_transition.h"

#include <set>

class sudoku_context:public FSM_base::FSM_context<sudoku_transition>
{
 public:
  sudoku_context(const unsigned int p_side_size);
  sudoku_context(const sudoku_context &p_context);

  // Methods inherited from interface
  const std::string to_string(void)const;
  void to_string(std::string &)const;
  
  // Specific methods
  void setValue(const unsigned int p_x,const unsigned int p_y,const unsigned int p_value);
  void getAuthorizedValues(const unsigned int p_x,const unsigned int p_y,std::set<unsigned int> &p_result);

 private:
  unsigned int getSquareId(const unsigned int p_x,const unsigned int p_y)const;

  const unsigned int m_context_size;
  const unsigned int m_side_size;

  std::set<unsigned int> *m_line_context;

  std::set<unsigned int> *m_column_context;

  std::set<unsigned int> *m_square_context;
};

#endif
