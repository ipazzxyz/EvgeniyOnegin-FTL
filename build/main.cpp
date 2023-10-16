#include "../include/Poem.h"
#include <iostream>

int main() {
  Composition c;
  std::cout << Poem(c, RNG());
  return 0;
}
