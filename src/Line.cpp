#include "../include/Line.h"
#include <iostream>
#define ACC 4

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
  return cnt > ACC;
}
inline std::string to_string(const Line &line) {
  std::string result;
  char *ptr = line.getBegin();
  while (ptr < line.getEnd()) {
    result.push_back(*ptr);
    ++ptr;
  }
  return result;
}
inline bool is_punct(const int &c) { return c >= ' ' && c <= '@'; }

std::ostream &operator<<(std::ostream &out, const Line &line) {
  out << to_string(line);
  return out;
}
