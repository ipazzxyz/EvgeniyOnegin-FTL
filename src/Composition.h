#pragma once
#include "Line.h"

class Composition {
public:
  Composition();
  Line operator[](const int &index) const;

private:
  Line *lines_;
};

std::ostream &operator<<(std::ostream &out, const Composition &composition);
