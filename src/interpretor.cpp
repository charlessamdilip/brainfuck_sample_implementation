#include<iostream>
using namespace std;

void init_message() {
  cout << endl;
  cout << "===================================== Sample BF Interpretor =====================================" << endl;
  cout << "Has an memory space of 10000 array initialized with 0 and zero indexed" << endl;
  cout << "Accepts string of brainfuck symbols +, -, >, <, [, ], ,, ." << endl;
  cout << "you can use the following commands to work with" << endl;
  cout << "print a or print a b, prints the memoryspace" << endl;
  cout << "set a val or print a b val, edits the memory space" << endl;
  cout << "reset a or print a bn resets the memory space with 0" << endl;
  cout << "commands with one argument a performs the operation on the memory space" << endl;
  cout << "commands with two argument a and b performs the operation on the rnage of memory space" << endl;
  cout << "aditional val parameter is required for the set command" << endl;
  cout << "quit, exits from the Interpretor" << endl;
  cout << endl << endl << endl;
}

int main() {
  init_message();
  while (true) {
    string in;
    cout << ">";
    getline(cin, in);
    cout << in << endl;
  }
  return 0;
}
