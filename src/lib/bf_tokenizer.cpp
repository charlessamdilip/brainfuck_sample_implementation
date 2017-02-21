#include "bf_tokenizer.h"

bool Tokenizer::match_view_op1(string* s){
  return regex_match(*s, regex("^view \\d{1,4}$"));
}
bool Tokenizer::match_view_op2(string* s){
  return regex_match(*s, regex("^view \\d{1,4} \\d{1,4}$"));
}
bool Tokenizer::match_viewi_op1(string* s){
  return regex_match(*s, regex("^viewi \\d{1,4}$"));
}
bool Tokenizer::match_viewi_op2(string* s){
  return regex_match(*s, regex("^viewi \\d{1,4} \\d{1,4}$"));
}
bool Tokenizer::match_set_op1(string* s){
  return regex_match(*s, regex("^set \\d{1,4} \\d+$"));
}
bool Tokenizer::match_set_op2(string* s){
  return regex_match(*s, regex("^set \\d{1,4} \\d{1,4} \\d+$"));
}
bool Tokenizer::match_quit(string* s){
  return regex_match(*s, regex("^quit$"));
}
bool Tokenizer::match_fb_grammar(string* s){
 if (!regex_match(*s, regex("^[-+,.\\[\\]><]+$"))) return false;
 int loop_count = 0;
 int n = s->length();
 for (int i = 0; i < n; ++i) {
   if (s->at(i) == '[') ++loop_count;
   else if (s->at(i) == ']') --loop_count;
   if (loop_count < 0) return false;
 }
 return loop_count == 0 ? true : false;
}
int Tokenizer::validate_input(string* s) {
  if (match_view_op1(s)) return view_op1;
  else if (match_view_op2(s)) return view_op2;
  else if (match_viewi_op1(s)) return viewi_op1;
  else if (match_viewi_op2(s)) return viewi_op2;
  else if (match_set_op1(s)) return set_op1;
  else if (match_set_op2(s)) return set_op2;
  else if (match_quit(s)) return quit;
  else if (match_fb_grammar(s)) return grammar;
  else return not_valid;
}
