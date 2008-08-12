
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
