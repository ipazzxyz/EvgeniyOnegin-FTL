#pragma once

#include <iterator>
#include <string>

class Line {
 public:
  void setBegin(char *begin);
  void setEnd(char *end);
  char *getBegin() const;
  char *getEnd() const;

 private:
  char *begin_;
  char *end_;
};

bool is_rhyme(const Line &line1, const Line &line2);
inline std::string to_string(const Line &line);
inline bool is_punct(const int &c);

std::ostream &operator<<(std::ostream &out, const Line &line);
