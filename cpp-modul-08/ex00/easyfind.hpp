#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include "main.h"

template <typename T>
int easyfind(T & t, int __unused target) {
  std::vector<int>::iterator it  = t.begin();
  while (it != t.end()) {
    if (*it == target)
      return *it;
    it++;
  }
  throw std::string("Not found");
}

#endif