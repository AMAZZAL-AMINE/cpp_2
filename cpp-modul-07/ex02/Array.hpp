#ifndef ARRAY_HPP
#define ARRAY_HPP

#include "main.h"

template <typename T>
class Array {
  private :
    T *array;
    unsigned int arrSize;
  public :
    Array();
    Array(Array const &src);
    Array &operator=(Array const &src);
    Array(unsigned int n);
    ~Array();
    unsigned int size() const;

    T & operator[](unsigned int i);
    class OutOfLimitsException : public std::exception {
      const char *what() const throw() {
        return "Out of limits";
      }
    };
};

#endif