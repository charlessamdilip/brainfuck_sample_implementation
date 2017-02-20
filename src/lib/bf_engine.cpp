#include "bf_engine.h"

Engine::Engine() {
  v = new vector<char>(10000);
  for (vector<char>::iterator itr= v->begin(); itr < v->end(); ++itr) *itr = 0;
  t = new Tokenizer();
  m = new Messages();
  m->display_welcome_message();
}

Engine::~Engine() {
  delete v;
}

void Engine::start() {
  while(true) {
    m->ps();
    string in;
    getline(cin, in);
    enum Command c = (enum Command)t->validate_input(&in);
    if (in.length() == 0) continue;
    else if (c == not_valid) m->not_valid_input(&in);
    else if (c == quit) return;
    else if (c == view_op1) {
      string *type = new string("view");
      int a = extract_a(&in, type);
      display(a, a);
    } else if (c == view_op2) {
      string *type = new string("view");
      int a = extract_a(&in, type, true);
      int b = extract_b(&in, type);
      display(a, b);
    } else if (c == set_op1) {
      string *type = new string("set");
      int a = extract_a(&in, type);
      int val = extract_val(&in);
      set(a, a, val);
    } else if (c == set_op2) {
      string *type = new string("set");
      int a = extract_a(&in, type, true);
      int b = extract_b(&in, type);
      int val = extract_val(&in, true);
      set(a, b, val);
    }
  }
}

int Engine::extract_a(string* s, string* type, bool multi) {
  string re = "^";
  re.append(*type);
  re.append(" (\\d{1,4})");
  if (multi) re.append(" \\d{1,4}");
  if (type->compare("set") == 0) re.append(" \\d+");
  re.append("$");
  return extract(s, &re);
}
int Engine::extract_b(string* s, string* type) {
  string re = "^";
  re.append(*type);
  re.append(" \\d{1,4} (\\d{1,4})");
  if (type->compare("set") == 0) re.append(" \\d+");
  re.append("$");
  return extract(s, &re);
}
int Engine::extract_val(string* s, bool multi) {
  string re = "^set \\d{1,4}";
  if (multi) re.append(" \\d{1,4}");
  re.append(" (\\d+)$");
  return extract(s, &re);
}

int Engine::extract(string* s, string* re) {
  smatch m;
  std::regex_search(*s, m, regex(*re));
  string res;
  for (auto x:m) res = x;
  string::size_type sz;
  return stoi(res, &sz);
}

void Engine::display(int a, int b) {
  vector<char>::iterator itr = v->begin() + a;
  int pos = a;
  while (itr < v-> begin() + b + 1) {
    int count = 10;
    while (count > 0 && itr < v-> begin() + b + 1) {
      cout << pos <<  ": " << *itr  << "\t";
      ++pos;
      --count;
      ++itr;
    }
    cout << endl;
  }
}

void Engine::set(int a, int b, int val) {
  for (vector<char>::iterator itr = v->begin() + a; itr < v-> begin() + b + 1; ++itr) *itr = val;
}
