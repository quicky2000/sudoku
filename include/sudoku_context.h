
#ifndef SUDOKU_CONTEXT_H
#define SUDOKU_CONTEXT_H

#include "FSM_context.h"
#include "sudoku_transition.h"

#include <set>

class sudoku_context:public FSM_context<sudoku_transition>
{
 public:
  sudoku_context(const unsigned int p_side_size);
  sudoku_context(const sudoku_context &p_context);

  // Methods inherited from interface
  string toString(void)const;
  
  // Specific methods
  void setValue(const unsigned int p_x,const unsigned int p_y,const unsigned int p_value);
  void getForbiddenValues(const unsigned int p_x,const unsigned int p_y,set<unsigned int> &p_result);

 private:
  unsigned int getSquareId(const unsigned int p_x,const unsigned int p_y)const;

  const unsigned int m_context_size;
  const unsigned int m_side_size;

  std::set<unsigned int> *m_line_context;

  std::set<unsigned int> *m_column_context;

  std::set<unsigned int> *m_square_context;
};

#endif
