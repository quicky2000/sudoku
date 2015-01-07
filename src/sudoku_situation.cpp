
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
#include "sudoku_situation.h"

#include <iostream>
#include <sstream>
#include <iomanip>
#include "math.h"
using namespace std;

//-----------------------------------------------------------------------------
string sudoku_situation::toString(void)const
{
  stringstream l_result;
  const string l_horizontal_separator = string(m_big_side_size*4+1,'-');
  const string l_horizontal_separator_2 = string(m_big_side_size*4+1,'+');
  for(unsigned int l_y = 0; l_y < m_big_side_size ; l_y++)
    {
      if( l_y % 3)
	{
	  l_result << l_horizontal_separator << endl ;
	}
      else
	{
	  l_result << l_horizontal_separator_2 << endl ;
	}

      for(unsigned int l_x = 0; l_x < m_big_side_size ; l_x++)
	{
      if( l_x % 3)
	{
	  l_result << "  "  ;
	}
      else
	{
	  l_result << "| "  ;
	}
	  unsigned char l_value = getValue(l_x,l_y);
	  if(l_value)
	    {
	      l_result << (unsigned int)l_value ;
	    }
	  else
	    {
	      l_result << " " ;
	    }
	  l_result << " ";
	}
      l_result << "|" << endl ;
    }
  l_result << l_horizontal_separator << endl ;
  return l_result.str();
}

//-----------------------------------------------------------------------------
string sudoku_situation::getStringId(void)const
{
  return m_unique_id;
}


//-----------------------------------------------------------------------------
sudoku_situation::~sudoku_situation(void)
{
}


//-----------------------------------------------------------------------------
sudoku_situation::sudoku_situation(const unsigned char p_side_size):
  m_side_size(p_side_size),
  m_big_side_size(p_side_size*p_side_size),
  m_value_string_width((unsigned int)ceil(log10(m_big_side_size))),
  m_unique_id(m_big_side_size*m_big_side_size*m_value_string_width,' ')
{
  this->setContext(new sudoku_context(m_side_size));
}

//-----------------------------------------------------------------------------
unsigned char sudoku_situation::getValue(const unsigned char p_x,const unsigned char p_y)const
{
  unsigned char l_result = 0;
  assert(p_x < m_big_side_size && p_y < m_big_side_size);
  map<pair<unsigned char,unsigned char>,unsigned char>::const_iterator l_iter = m_values.find(pair<unsigned char,unsigned char>(p_x,p_y));
  if(l_iter != m_values.end())
    {
      l_result = l_iter->second;
    }
  return l_result;
}

//-----------------------------------------------------------------------------
void sudoku_situation::setValue(const unsigned char p_x,const unsigned char p_y,const unsigned char p_value)
{
  assert(p_x < m_big_side_size && p_y < m_big_side_size);
  assert(!m_values.count(pair<unsigned char,unsigned char>(p_x,p_y)));

  // Inserting value in value map
  m_values.insert(map<pair<unsigned char,unsigned char>,unsigned char>::value_type(pair<unsigned char,unsigned char>(p_x,p_y),p_value));

  // Updating the unique identifier
  stringstream l_stream;
  l_stream << setw(m_value_string_width) << setfill('0') << (unsigned int)p_value ;
  m_unique_id.replace((p_x + m_big_side_size * p_y)*m_value_string_width,m_value_string_width,l_stream.str());

  //Updating context according to the new value
  getContext()->setValue(p_x,p_y,p_value);
}

//-----------------------------------------------------------------------------
bool sudoku_situation::isFinal(void)const
{
  return m_values.size()==m_big_side_size*m_big_side_size;
}

//-----------------------------------------------------------------------------
bool sudoku_situation::less(const FSM_situation_if *p_situation)const
{
  return this->less(dynamic_cast<const sudoku_situation*>(p_situation)); 
}

//-----------------------------------------------------------------------------
bool sudoku_situation::less(const sudoku_situation *p_situation)const
{
  return m_values<p_situation->m_values; 
}
