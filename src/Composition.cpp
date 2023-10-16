#include "../include/Composition.h"
#include <fstream>
#include <ostream>
#define FILENAME "../lib/data.txt"
#define LEN 250338
#define SIZE 5310

Composition::Composition() {
  std::ifstream in(FILENAME);
  char *begin = new char[LEN];
  in.read(begin, LEN);
  this->lines_ = new Line[SIZE];
  this->lines_[0].setBegin(begin);

  for (int i = 0, j = 0; i < LEN; ++i) {
    if (*(begin + i) == '\n') {
      this->lines_[j].setEnd(begin + i);
      ++j;
      this->lines_[j].setBegin(begin + i + 1);
    }
  }
  this->lines_[SIZE - 1].setEnd(begin + LEN - 1);
}
Line Composition::operator[](const int &index) const {
  return this->lines_[index];
}

std::ostream &operator<<(std::ostream &out, Composition const &composition) {
  out << composition[0].getBegin() << std::endl;
  return out;
}
