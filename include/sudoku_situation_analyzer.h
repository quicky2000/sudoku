#ifndef SUDOKU_SITUATION_ANALYZER
#define SUDOKU_SITUATION_ANALYZER

#include "FSM_situation_analyzer.h"
#include "sudoku_situation.h"
#include "sudoku_transition.h"

class sudoku_situation_analyzer: public FSM_situation_analyzer<sudoku_situation,sudoku_transition>
{
 public:
  // Constructors and Destructors
  sudoku_situation_analyzer(const unsigned int p_side_size);
  ~sudoku_situation_analyzer(void);

  // Methods inherited from FSM_situation_analyzer
  string toString(void);
  vector<sudoku_transition*> getTransitions(sudoku_situation* p_situation);

 private:
  const unsigned int m_big_side_size;

};
#endif /* SUDOKU_SITUATION_ANALYZER */
