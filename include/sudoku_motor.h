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

#ifndef SUDOKU_MOTOR_H
#define SUDOKU_MOTOR_H

#include "FSM_motor.h"
#include "sudoku_situation.h"
#include "sudoku_transition.h"

class sudoku_motor:public FSM_motor<sudoku_situation,sudoku_transition>
{
 public:
  // Constructors and destructors
  sudoku_motor(void);
  ~sudoku_motor(void);
  
  // Methods inherited from FSM_motor
  string toString(void);
  sudoku_situation* run(sudoku_situation* p_situation, sudoku_transition *p_transition);
};

#endif
