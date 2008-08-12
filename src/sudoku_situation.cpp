
#include "sudoku_situation.h"

#include <iostream>
#include <sstream>
using namespace std;

//-----------------------------------------------------------------------------
string sudoku_situation::toString(void)const
{
  stringstream l_result;
  const string l_horizontal_separator = string(m_big_side_size*4+1,'-');
  for(unsigned int l_y = 0; l_y < m_big_side_size ; l_y++)
    {
      l_result << l_horizontal_separator << endl ;
      for(unsigned int l_x = 0; l_x < m_big_side_size ; l_x++)
	{
	  l_result << "| "  ;
	  unsigned int l_value = getValue(l_x,l_y);
	  if(l_value)
	    {
	      l_result << l_value ;
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
sudoku_situation::~sudoku_situation(void)
{
}


//-----------------------------------------------------------------------------
sudoku_situation::sudoku_situation(const unsigned int p_side_size):
  m_side_size(p_side_size),
  m_big_side_size(p_side_size*p_side_size)
{
  this->setContext(new sudoku_context(m_side_size));
}

//-----------------------------------------------------------------------------
unsigned int sudoku_situation::getValue(const unsigned int p_x,const unsigned int p_y)const
{
  unsigned int l_result = 0;
  assert(p_x >= 0 && p_y >= 0 && p_x < m_big_side_size && p_y < m_big_side_size);
  map<pair<unsigned int,unsigned int>,unsigned int>::const_iterator l_iter = m_values.find(pair<unsigned int,unsigned int>(p_x,p_y));
  if(l_iter != m_values.end())
    {
      l_result = l_iter->second;
    }
  return l_result;
}

//-----------------------------------------------------------------------------
void sudoku_situation::setValue(const unsigned int p_x,const unsigned int p_y,const unsigned int p_value)
{
  assert(p_x >= 0 && p_y >= 0 && p_x < m_big_side_size && p_y < m_big_side_size);
  assert(!m_values.count(pair<unsigned int,unsigned int>(p_x,p_y)));
  m_values.insert(map<pair<unsigned int,unsigned int>,unsigned int>::value_type(pair<unsigned int,unsigned int>(p_x,p_y),p_value));
  getContext()->setValue(p_x,p_y,p_value);
}
