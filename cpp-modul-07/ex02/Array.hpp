#ifndef ARRAY_HPP
#define ARRAY_HPP


#include "main.h"

template <typename T>
class Array {
  private :
    T *array;
    unsigned int arrSize;
  public :
    Array() :array(NULL), arrSize(0) {}
    Array(Array const &src) {
      *this = src;
    }
    Array & operator=(Array const &src){
      if (this != &src) {
        delete [] this->array;
        this->array = src.array;
        this->arrSize = src.arrSize;
      }
      return *this;
    }
    ~Array() {
      delete [] this->array;
    }
    Array(unsigned int n)  {
      this->array = new T[n];
      this->arrSize = n;
    }

    unsigned int size() const {
      return this->arrSize;
    }

    T & operator[](unsigned int i) {
      if (i >= this->arrSize) {
        throw Array::OutOfLimitsException();
      }
      return this->array[i]; 
    }

    class OutOfLimitsException : public std::exception {
      const char *what() const throw() {
        return "Out of limits";
      }
    };
};

#endif
