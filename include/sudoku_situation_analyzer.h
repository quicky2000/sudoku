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
#ifndef SUDOKU_SITUATION_ANALYZER
#define SUDOKU_SITUATION_ANALYZER

#include "FSM_situation_analyzer.h"
#include "sudoku_situation.h"
#include "sudoku_transition.h"

class sudoku_situation_analyzer: public FSM_base::FSM_situation_analyzer<sudoku_situation,sudoku_transition>
{
 public:
  // Constructors and Destructors
  sudoku_situation_analyzer(const unsigned int p_side_size);
  ~sudoku_situation_analyzer(void);

  // Methods inherited from FSM_situation_analyzer
  const std::string & get_class_name(void)const;
  std::vector<const sudoku_transition *> & get_transitions(sudoku_situation & p_situation);

 private:
  const unsigned int m_big_side_size;
  static const std::string m_class_name;    

};
#endif /* SUDOKU_SITUATION_ANALYZER */
