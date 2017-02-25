#include "bf_executor.h"

bool Executor::execute(string* s, vector<char>* v, vector<char>::iterator* itr, Messages* m) {
  vector<char> temp_v = *v;
  vector<char>::iterator temp_itr = *itr;
  int n = s->length();
  stack<int> S;

  for (int i = 0; i < n;) {
      switch(s->at(i)) {
        case '+':
          ++(**itr);
          ++i;
          break;
        case '-':
          --(**itr);
          ++i;
          break;
        case '>':
          if ((*itr) + 1 == v->end()) {
            *v = temp_v;
            *itr = temp_itr;
            m->out_of_bounds();
            return false;
          }
          ++i;
          ++(*itr);
          break;
        case '<':
          if ((*itr) == v->begin()) {
            *v = temp_v;
            *itr = temp_itr;
            m->out_of_bounds(true);
            return false;
          }
          ++i;
          --(*itr);
          break;
        case '[':
          S.push(i);
          ++i;
          break;
        case ']':
          if (**itr == 0) {
            ++i;
            S.pop();
          }
          else i = S.top() + 1;
          break;
        case '.':
          ++i;
          cout << **itr;
          break;
        case ',':
          ++i;
          cin >> **itr;
          break;
        default:
          break;
      }
  }

  return true;
}
