#include "bf_messages.h"

void Messages::display_welcome_message() {
  cout << endl;
  cout << "===================================== Sample BF Interpretor =====================================" << endl;
  cout << "Has an memory space of 10000 array initialized with 0 and zero indexed" << endl;
  cout << "Accepts string of brainfuck symbols +, -, >, <, [, ], ,, ." << endl;
  cout << "you can use the following commands to work with" << endl;
  cout << "view a or view a b, prints the memoryspace" << endl;
  cout << "set a val or set a b val, edits the memory space" << endl;
  cout << "commands with one argument a performs the operation on the memory space" << endl;
  cout << "commands with two argument a and b performs the operation on the rnage of memory space" << endl;
  cout << "aditional val parameter is required for the set command" << endl;
  cout << "quit, exits from the Interpretor" << endl;
  cout << endl << endl << endl;
}

void Messages::ps() {
  cout << ">>> ";
}

void Messages::not_valid_input(string *s) {
  cout << "The input string `" << *s << "` is unable to be processed." << endl << endl;
}

void Messages::out_of_bounds(int pos) {
  cout << "Array index out of bounds: " << pos << endl << endl;
}
