#include "sudoku_transition.h"

#include <sstream>
using namespace std;

//-----------------------------------------------------------------------------
sudoku_transition::sudoku_transition
(
 unsigned int p_x,
 unsigned int p_y,
 unsigned int p_value
):
  m_x(p_x),
  m_y(p_y),
  m_value(p_value)
{
}

//-----------------------------------------------------------------------------
sudoku_transition::~sudoku_transition(void)
{
}

//-----------------------------------------------------------------------------
string sudoku_transition::toString(void)const
{
  stringstream l_stream;
  l_stream << m_value << " => (" << m_x << "," << m_y << ")" ;
  return l_stream.str();
}

//-----------------------------------------------------------------------------
unsigned int sudoku_transition::getX(void)const
{
  return m_x;
}

//-----------------------------------------------------------------------------
unsigned int sudoku_transition::getY(void)const
{
  return m_y;
}

//-----------------------------------------------------------------------------
unsigned int sudoku_transition::getValue(void)const
{
  return m_value;
}
