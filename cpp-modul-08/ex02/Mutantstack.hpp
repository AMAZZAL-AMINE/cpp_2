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
// https://www.reddit.com/r/learnprogramming/comments/vpgey4/whats_the_proper_way_to_compile_c_template/?rdt=40554&onetap_auto=true&one_tap=true
#endif
