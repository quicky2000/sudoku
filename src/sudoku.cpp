#include "sudoku.h"
#include "sudoku_motor.h"
#include "sudoku_situation_analyzer.h"

#include <iostream>
using namespace std;

//-----------------------------------------------------------------------------
sudoku::sudoku(void):FSM<sudoku_situation,sudoku_transition>("sudoku",new sudoku_motor(), new sudoku_situation_analyzer(3))
{
	setSituation(new sudoku_situation(3));

	//Facile
/*	getSituation()->setValue(3,0,8);
	getSituation()->setValue(7,0,7);

	getSituation()->setValue(1,1,4);
	getSituation()->setValue(5,1,2);
	getSituation()->setValue(6,1,8);
	getSituation()->setValue(8,1,5);

	getSituation()->setValue(0,2,8);
	getSituation()->setValue(1,2,5);
	getSituation()->setValue(3,2,7);
	getSituation()->setValue(6,2,2);
	getSituation()->setValue(8,2,3);

	getSituation()->setValue(2,3,4);
	getSituation()->setValue(6,3,5);
	getSituation()->setValue(7,3,9);
	getSituation()->setValue(8,3,1);

	getSituation()->setValue(1,4,7);
	getSituation()->setValue(2,4,9);
	getSituation()->setValue(6,4,3);
	getSituation()->setValue(7,4,2);

	getSituation()->setValue(0,5,2);
	getSituation()->setValue(1,5,8);
	getSituation()->setValue(2,5,5);
	getSituation()->setValue(6,5,7);

	getSituation()->setValue(0,6,5);
	getSituation()->setValue(2,6,1);
	getSituation()->setValue(5,6,7);
	getSituation()->setValue(7,6,8);
	getSituation()->setValue(8,6,6);

	getSituation()->setValue(0,7,7);
	getSituation()->setValue(2,7,3);
	getSituation()->setValue(3,7,6);
	getSituation()->setValue(7,7,5);

	getSituation()->setValue(1,8,6);
	getSituation()->setValue(5,8,1);*/

	//Moyen
	getSituation()->setValue(0,0,3);
	getSituation()->setValue(4,0,5);
	getSituation()->setValue(6,0,7);

	getSituation()->setValue(0,1,7);
	getSituation()->setValue(2,1,8);
	getSituation()->setValue(3,1,9);
	getSituation()->setValue(7,1,1);
	getSituation()->setValue(8,1,2);

	getSituation()->setValue(5,2,4);

	getSituation()->setValue(0,3,5);
	getSituation()->setValue(5,3,9);
	getSituation()->setValue(6,3,6);

	getSituation()->setValue(1,4,3);
	getSituation()->setValue(2,4,4);
	getSituation()->setValue(6,4,2);
	getSituation()->setValue(7,4,9);

	getSituation()->setValue(2,5,7);
	getSituation()->setValue(3,5,6);
	getSituation()->setValue(8,5,4);

	getSituation()->setValue(3,6,2);

	getSituation()->setValue(0,7,9);
	getSituation()->setValue(1,7,6);
	getSituation()->setValue(5,7,7);
	getSituation()->setValue(6,7,5);
	getSituation()->setValue(8,7,1);

	getSituation()->setValue(2,8,1);
	getSituation()->setValue(4,8,9);
	getSituation()->setValue(8,8,7);

}

//-----------------------------------------------------------------------------
sudoku::~sudoku(void)
{
}

//-----------------------------------------------------------------------------
void sudoku::configure(void)
{
}

//-----------------------------------------------------------------------------
string sudoku::toString(void)const
{
	string l_result = "__FUNCTION__ Not implemented";
	return l_result;
}

//-----------------------------------------------------------------------------
FSM_if* createGameOfLife()
{
	return new sudoku();
}

//-----------------------------------------------------------------------------
extern "C"
{
	void registerFsm(map<string,FSM_creator> *p_factory)
	{
		registerFsm("sudoku",createGameOfLife,p_factory);
	}
}
