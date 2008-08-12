#ifndef SUDOKU_TRANSITION
#define SUDOKU_TRANSITION

#include "FSM_transition_if.h"

class sudoku_transition: public FSM_transition_if
{
 public:
  // Constructors && Destructors
  sudoku_transition(unsigned int p_x,unsigned int p_y,unsigned int p_value);
  ~sudoku_transition(void);
  
  // Methods inherited from interface
  string toString(void)const;
  
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
