#pragma once

#include "line.hpp"

class Composition {
 public:
  Composition();
  Line operator[](const int &index) const;
  ~Composition();

 private:
  Line *lines_;
};

std::ostream &operator<<(std::ostream &out, const Composition &composition);
