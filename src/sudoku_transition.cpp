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
const string sudoku_transition::to_string(void)const
{
  stringstream l_stream;
  l_stream << m_value << " => (" << m_x << "," << m_y << ")" ;
  return l_stream.str();
}

//-----------------------------------------------------------------------------
void sudoku_transition::to_string(std::string & p_result)const
{
  stringstream l_stream;
  l_stream << m_value << " => (" << m_x << "," << m_y << ")" ;
  p_result = l_stream.str();
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
