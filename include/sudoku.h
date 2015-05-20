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

#ifndef SUDOKU_BASE_H
#define SUDOKU_BASE_H

#include "FSM.h"
#include "sudoku_situation.h"
#include "sudoku_transition.h"
#include "sudoku_context.h"

class sudoku:public FSM_base::FSM<sudoku_situation,sudoku_transition>
{
 public:
  // Constructors && Destructors
  sudoku(void);
  ~sudoku(void);

  // Methods inherited from FSM
  void configure(void);
  const std::string & get_class_name()const;
  void compute_transition_weights(std::vector<FSM_weighted_transition_index_if*> &p_vector)const;

  private:
  static const std::string m_class_name;
};
#endif
