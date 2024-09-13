#include "rng.hpp"

#include <cstdlib>
#include <ctime>

#define SIZE 5310

RNG::RNG() {
  std::srand(std::time(nullptr));
  for (int i = 0; i < 7; ++i) {
    this->data_[i] = rand() % SIZE;
  }
}

int RNG::operator[](const int &index) const { return this->data_[index]; }
