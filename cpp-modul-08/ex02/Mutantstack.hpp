#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include "main.h"

template<typename T>
class Mutantstack : std::stack<T> {
    private :
    public :
      Mutantstack() {}
      Mutantstack(Mutantstack const &src) {}
      Mutantstack &operator=(Mutantstack const &src) {}
      ~Mutantstack() {}
  };

#endif