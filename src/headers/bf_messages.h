#include<iostream>
#include<string>
using namespace std;
class Messages {
public:
  void display_welcome_message();
  void ps();
  void not_valid_input(string *s);
  void out_of_bounds(int);
};
