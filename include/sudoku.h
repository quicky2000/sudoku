
#ifndef SUDOKU_BASE_H
#define SUDOKU_BASE_H

#include "FSM.h"
#include "sudoku_situation.h"
#include "sudoku_transition.h"
#include "sudoku_context.h"

class sudoku:public FSM<sudoku_situation,sudoku_transition>
{
	public:
	// Constructors && Destructors
	sudoku(void);
	~sudoku(void);

	// Methods inherited from FSM
	void configure(void);
	string toString(void)const;
};
#endif
