#pragma once
#include "Composition.h"
#include "RNG.h"

class Poem {
public:
  Poem(const Composition &composition, const int &index0, const int &index2,
       const int &index4, const int &index5, const int &index10,
       const int &index11, const int &index12);
  Poem(const Composition &composition, const RNG &rng);

  Line *getLines() const;

private:
  Line *lines_;
};

inline int find_rhyme(const Composition &composition, const int &index);
std::ostream &operator<<(std::ostream &out, const Poem &Poem);
