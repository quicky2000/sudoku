#include "sudoku_motor.h"

#include <string>
using namespace std;

//-----------------------------------------------------------------------------
string sudoku_motor::toString(void)
{
  string l_result = "sudoku_motor";
  return l_result;
}

//-----------------------------------------------------------------------------
sudoku_situation* sudoku_motor::run(sudoku_situation* p_situation,sudoku_transition *p_transition)
{
  sudoku_situation *l_result = new sudoku_situation(*p_situation);
  l_result->setValue(p_transition->getX(),p_transition->getY(),p_transition->getValue());
  return l_result;
}

//-----------------------------------------------------------------------------
sudoku_motor::~sudoku_motor(void)
{
}

//-----------------------------------------------------------------------------
sudoku_motor::sudoku_motor(void)
{
}

