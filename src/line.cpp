#include "line.hpp"

#define ACCMIN 3
#define ACCMAX 6

void Line::setBegin(char *begin) { this->begin_ = begin; }
void Line::setEnd(char *end) { this->end_ = end; }
char *Line::getBegin() const { return this->begin_; }
char *Line::getEnd() const { return this->end_; }

bool is_rhyme(const Line &line1, const Line &line2) {
  std::string s1 = to_string(line1), s2 = to_string(line2);
  auto it1 = s1.rbegin(), it2 = s2.rbegin();
  int cnt = 0;
  while (!s1.empty() && !s2.empty()) {
    while (!s2.empty() && is_punct(s1.back())) {
      s1.pop_back();
    }
    while (!s2.empty() && is_punct(s2.back())) {
      s2.pop_back();
    }
    if (!s1.empty() && !s2.empty() && s1.back() == s2.back()) {
      ++cnt;
      s1.pop_back();
      s2.pop_back();
    } else {
      break;
    }
  }
  cnt /= 2;
  return cnt >= ACCMIN && cnt <= ACCMAX;
}
inline std::string to_string(const Line &line) {
  std::string result;
  char *ptr = line.getBegin();
  while (ptr && ptr < line.getEnd()) {
    result.push_back(*ptr);
    ++ptr;
  }
  return result;
}
inline bool is_punct(const int &c) { return c >= 0; }

std::ostream &operator<<(std::ostream &out, const Line &line) {
  out << to_string(line);
  return out;
}
