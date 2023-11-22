#include "main.h"

template<typename T>
Array<T>::Array() :array(NULL), arrSize(0) {}

template<typename T>
Array<T>::Array(Array const &src){
  *this = src;
}

template<typename T>
Array<T> & Array<T>::operator=(Array const &src){
  if (this != &src) {
    delete [] this->array;
    this->array = src.array;
    this->arrSize = src.arrSize;
  }
  return *this;
}

template<typename T>
Array<T>::~Array() {
  delete [] this->array;
}

template<typename T>
Array<T>::Array(unsigned int n) : arrSize(n), array(new T[n]) {}

template<typename T>
T &Array<T>::operator[](unsigned int i) {
  if (i >= this->arrSize) {
    throw Array::OutOfLimitsException();
  }
  return this->array[i]; 
}

template<typename T>
unsigned int Array<T>::size() const {
  return this->arrSize;
}
