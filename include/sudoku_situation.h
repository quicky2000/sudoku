#ifndef SUDOKU_SITUATION_H
#define SUDOKU_SITUATION_H

#include "FSM_situation.h"
#include "sudoku_context.h"

#include <map>

class sudoku_situation:public FSM_situation<sudoku_context>
{
 public:
  // Constructors and destructors
  sudoku_situation(const unsigned char m_side_size);
  ~sudoku_situation(void);
  
  // Methods inherited from FSM_situation
  string toString(void)const;
  string getStringId(void)const;
  bool isFinal(void)const;
  bool less(const FSM_situation_if *p_object2)const;

  // Dedicated methods
  unsigned char getValue(const unsigned char p_x,const unsigned char p_y)const;
  void setValue(const unsigned char p_x,const unsigned char p_y,const unsigned char p_value);
  bool less(const sudoku_situation *p_situation)const;

 private:
  const unsigned char m_side_size;
  const unsigned char m_big_side_size;
  const unsigned char m_value_string_width;
  string m_unique_id;
  std::map<std::pair<unsigned char,unsigned char>, unsigned char> m_values;
};

#endif
