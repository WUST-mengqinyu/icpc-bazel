#include "inner/enumerate/bracket.hpp"
#include "inner/prelude"

using namespace std;

MAIN() {
  int n;
  R(n);
  BracketSequenceGenerator generator(n);
  for (auto &s: generator) {
    W(s);
  }
  W(n);
}
