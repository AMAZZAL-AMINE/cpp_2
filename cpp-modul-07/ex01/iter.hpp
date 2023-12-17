#ifndef ITER_HPP
#define ITER_HPP

#include "main.h"

template <typename T>
void iter(T *array, int length, void (*fun)(T &)) {
  int i = 0;
  while (i < length) {
    fun(array[i]);
    i++;
  }
}

template <typename T>
void iter(T *array, int length, void (*fun)(const T &)) {
  int i = 0;
  while (i < length) {
    fun(array[i]);
    i++;
  }
}

template <typename T>
void printer(T & data) {
  std::cout << data << std::endl;
}

#endif