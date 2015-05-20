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
#include "sudoku_motor.h"

#include <string>
using namespace std;

//-----------------------------------------------------------------------------
const std::string & sudoku_motor::get_class_name(void)const
{
  return m_class_name;
}

//-----------------------------------------------------------------------------
sudoku_situation & sudoku_motor::run(const sudoku_situation & p_situation,
                                     const sudoku_transition & p_transition)
{
  sudoku_situation *l_result = new sudoku_situation(p_situation);
  l_result->setValue(p_transition.getX(),p_transition.getY(),p_transition.getValue());
  return *l_result;
}

//-----------------------------------------------------------------------------
sudoku_motor::~sudoku_motor(void)
{
}

//-----------------------------------------------------------------------------
sudoku_motor::sudoku_motor(void)
{
}

const std::string sudoku_motor::m_class_name = "sudoku_motor";
//EOF

