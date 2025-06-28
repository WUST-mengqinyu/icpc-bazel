#ifndef ENUM_BRACKET
#define ENUM_BRACKET

#include "inner/prelude"// IWYU pragma: keep

class BracketSequenceGenerator {
  using S = std::string;
  using VS = std::vector<S>;
  using SIter = VS::const_iterator;

  private:
  int n;
  VS seqs;

  // 递归生成括号序列
  void gen(S cur, int o, int c) {
    if (o == n && c == n) {
      seqs.push_back(cur);
      return;
    }

    if (o < n) {
      gen(cur + "(", o + 1, c);
    }

    if (c < o) {
      gen(cur + ")", o, c + 1);
    }
  }

  public:
  class Iter {
private:
    SIter it;

public:
    using iterator_category = std::forward_iterator_tag;
    using value_type = S;
    using difference_type = std::ptrdiff_t;
    using pointer = const S *;
    using reference = const S &;

    Iter(SIter iter) : it(iter) {}

    const S &operator*() const { return *it; }
    const S *operator->() const { return &(*it); }

    Iter &operator++() {
      ++it;
      return *this;
    }

    Iter operator++(int) {
      Iter temp = *this;
      ++it;
      return temp;
    }

    bool operator==(const Iter &other) const {
      return it == other.it;
    }

    bool operator!=(const Iter &other) const {
      return it != other.it;
    }
  };

  BracketSequenceGenerator(int p) : n(p) {
    if (n > 0) {
      gen("", 0, 0);
    }
  }

  Iter begin() const {
    return Iter(seqs.begin());
  }

  Iter end() const {
    return Iter(seqs.end());
  }

  size_t size() const {
    return seqs.size();
  }
};

#endif