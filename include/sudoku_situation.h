#ifndef SUDOKU_SITUATION_H
#define SUDOKU_SITUATION_H

#include "FSM_situation.h"
#include "sudoku_context.h"

#include <map>

class sudoku_situation:public FSM_situation<sudoku_context>
{
 public:
  // Constructors and destructors
  sudoku_situation(const unsigned int m_side_size);
  ~sudoku_situation(void);
  
  // Methods inherited from FSM_situation
  string toString(void)const;
  
  // Dedicated methods
  unsigned int getValue(const unsigned int p_x,const unsigned int p_y)const;
  void setValue(const unsigned int p_x,const unsigned int p_y,const unsigned int p_value);

 private:
  const unsigned int m_side_size;
  const unsigned int m_big_side_size;
  std::map<std::pair<unsigned int,unsigned int>, unsigned int> m_values;
};

#endif
