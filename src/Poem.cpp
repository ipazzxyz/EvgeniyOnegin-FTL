#include "../include/Poem.h"
#include <ostream>
#define SIZE 5310

Poem::Poem(const Composition &composition, const int &index0, const int &index2,
           const int &index4, const int &index5, const int &index8,
           const int &index9, const int &index12) {
  this->lines_ = new Line[14];
  this->lines_[0] = composition[index0];
  this->lines_[1] = composition[find_rhyme(composition, index0)];
  this->lines_[2] = composition[index2];
  this->lines_[3] = composition[find_rhyme(composition, index2)];
  this->lines_[4] = composition[index4];
  this->lines_[5] = composition[index5];
  this->lines_[6] = composition[find_rhyme(composition, index4)];
  this->lines_[7] = composition[find_rhyme(composition, index5)];
  this->lines_[8] = composition[index8];
  this->lines_[9] = composition[index9];
  this->lines_[10] = composition[find_rhyme(composition, index9)];
  this->lines_[11] = composition[find_rhyme(composition, index8)];
  this->lines_[12] = composition[index12];
  this->lines_[13] = composition[find_rhyme(composition, index12)];
}
Poem::Poem(const Composition &composition, const RNG &rng) {
  this->lines_ = new Line[14];
  this->lines_[0] = composition[rng[0]];
  this->lines_[1] = composition[find_rhyme(composition, rng[0])];
  this->lines_[2] = composition[rng[1]];
  this->lines_[3] = composition[find_rhyme(composition, rng[1])];
  this->lines_[4] = composition[rng[2]];
  this->lines_[5] = composition[rng[3]];
  this->lines_[6] = composition[find_rhyme(composition, rng[2])];
  this->lines_[7] = composition[find_rhyme(composition, rng[3])];
  this->lines_[8] = composition[rng[4]];
  this->lines_[9] = composition[rng[5]];
  this->lines_[10] = composition[find_rhyme(composition, rng[5])];
  this->lines_[11] = composition[find_rhyme(composition, rng[4])];
  this->lines_[12] = composition[rng[6]];
  this->lines_[13] = composition[find_rhyme(composition, rng[6])];
}

Line *Poem::getLines() const { return this->lines_; }

Poem::~Poem() { delete[] this->lines_; }

inline int find_rhyme(const Composition &composition, const int &index) {
  for (int i = 1; i < SIZE; ++i) {
    if (is_rhyme(composition[index], composition[(i + index) % SIZE])) {
      return (i + index) % SIZE;
    }
  }
  return index;
}

std::ostream &operator<<(std::ostream &out, const Poem &poem) {
  for (int i = 0; i < 14; ++i) {
    out << poem.getLines()[i] << std::endl;
  }
  return out;
}
