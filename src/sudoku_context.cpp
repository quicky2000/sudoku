#include "sudoku_context.h"

#include <sstream>
using namespace std;

//-----------------------------------------------------------------------------
sudoku_context::sudoku_context(const unsigned int p_side_size):
  m_context_size(p_side_size*p_side_size),
  m_side_size(p_side_size)
{
  m_line_context = new set<unsigned int>[m_context_size];
  m_column_context = new set<unsigned int>[m_context_size];
  m_square_context = new set<unsigned int>[m_context_size];
}

//-----------------------------------------------------------------------------
sudoku_context::sudoku_context(const sudoku_context &p_context):
  m_context_size(p_context.m_context_size),
  m_side_size(p_context.m_side_size)
{
  m_line_context = new set<unsigned int>[m_context_size];
  for(unsigned int l_i=0;l_i<m_context_size;l_i++)
    {
      m_line_context[l_i] = p_context.m_line_context[l_i];
    }

  m_column_context = new set<unsigned int>[m_context_size];
  for(unsigned int l_i=0;l_i<m_context_size;l_i++)
    {
      m_column_context[l_i] = p_context.m_column_context[l_i];
    }

  m_square_context = new set<unsigned int>[m_context_size];
  for(unsigned int l_i=0;l_i<m_context_size;l_i++)
    {
      m_square_context[l_i] = p_context.m_square_context[l_i];
    }
}

//-----------------------------------------------------------------------------
string sudoku_context::toString(void)const
{
  return "__FUNCTION__ Not implemented";
}

//-----------------------------------------------------------------------------
void sudoku_context::setValue(const unsigned int p_x,const unsigned int p_y,const unsigned int p_value)
{
  assert(p_x >= 0 && p_y >=0 && p_value > 0 && p_x<m_context_size && p_y < m_context_size && p_value <= m_context_size);
  m_line_context[p_y].insert(p_value);
  m_column_context[p_x].insert(p_value);
  m_square_context[getSquareId(p_x,p_y)].insert(p_value);
}

void sudoku_context::getForbiddenValues(const unsigned int p_x,const unsigned int p_y,set<unsigned int> &p_result)
{
  set<unsigned int> l_result;
  set_union( m_line_context[p_y].begin(),m_line_context[p_y].end(),m_column_context[p_x].begin(),m_column_context[p_x].end(),inserter(l_result,l_result.begin()));
  set_union( m_square_context[getSquareId(p_x,p_y)].begin(), m_square_context[getSquareId(p_x,p_y)].end(),l_result.begin(),l_result.end(),inserter(p_result,p_result.begin()));
}

//-----------------------------------------------------------------------------
unsigned int sudoku_context::getSquareId(const unsigned int p_x,const unsigned int p_y)const
{
  const unsigned int l_x = p_x / m_side_size;
  const unsigned int l_y = p_y / m_side_size;
  return m_side_size * l_y + l_x ;
}