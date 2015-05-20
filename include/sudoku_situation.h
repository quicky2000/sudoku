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
#ifndef SUDOKU_SITUATION_H
#define SUDOKU_SITUATION_H

#include "FSM_situation.h"
#include "sudoku_context.h"

#include <map>

class sudoku_situation:public FSM_base::FSM_situation<sudoku_context>
{
 public:
  // Constructors and destructors
  sudoku_situation(const unsigned char m_side_size);
  ~sudoku_situation(void);
  
  // Methods inherited from FSM_situation
  const std::string to_string(void)const;
  void to_string(std::string &)const;
  const std::string get_string_id(void)const;
  void get_string_id(std::string & p_string_id)const;
  bool is_final(void)const;
  bool less(const FSM_situation_if *p_object2)const;

  // Dedicated methods
  unsigned char getValue(const unsigned char p_x,const unsigned char p_y)const;
  void setValue(const unsigned char p_x,const unsigned char p_y,const unsigned char p_value);
  bool less(const sudoku_situation *p_situation)const;

 private:

  const unsigned char m_side_size;
  const unsigned char m_big_side_size;
  const unsigned char m_value_string_width;
  std::string m_unique_id;
  std::map<std::pair<unsigned char,unsigned char>, unsigned char> m_values;
};

#endif
