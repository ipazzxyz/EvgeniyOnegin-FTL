#include <iostream>

#include "poem.hpp"

int main() {
  Composition c;
  std::cout << Poem(c, RNG());
  return 0;
}
