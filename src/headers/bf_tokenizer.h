#include<iostream>
#include<string>
#include<regex>

#include "bf_commands.h"

using namespace std;

class Tokenizer{
private:
  bool match_view_op1(string*);
  bool match_view_op2(string*);
  bool match_set_op1(string*);
  bool match_set_op2(string*);
  bool match_quit(string*);
  bool match_fb_grammar(string*);
public:
  int  validate_input(string*);
};
