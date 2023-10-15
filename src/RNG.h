#pragma once

class RNG {
public:
  RNG();
  RNG(const int &seed);
  int operator[](const int &index) const;

private:
  int data_[7];
};
