#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include "main.h"

template<typename T>
class MutantStack : public std::stack<T> {
  private :
  public :
    typedef typename std::stack<T>::container_type::iterator iterator;
    MutantStack() {}

    MutantStack(MutantStack __unused const  &src) {}
    MutantStack &operator=(MutantStack __unused const  &src) {}
    ~MutantStack() {} 

    iterator begin() { 
      return std::stack<T>::c.begin();
    }
    iterator end() {
      return std::stack<T>::c.end();
    }
};

#endif
