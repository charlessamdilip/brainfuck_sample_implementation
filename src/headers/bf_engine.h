#include <vector>
#include <regex>
#include "bf_tokenizer.h"
#include "bf_executor.h"

using namespace std;

class Engine {
private:
  vector<char> *v;
  vector<char>::iterator itr;
  Messages *m;
  Tokenizer *t;
  Executor *ex;
  int extract_a(string*, string*, bool multi=false);
  int extract_b(string*, string*);
  int extract_val(string*, bool multi = false);
  int extract(string*, string*);
  void display(int, int);
  void displayi(int, int);
  void set(int, int, int);
public:
  Engine();
  ~Engine();
  void start();
};
