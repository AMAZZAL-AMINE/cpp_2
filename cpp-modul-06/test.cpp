#include <iostream>

typedef struct gg {
  int i;
} t_gg;

class A {
  public:
    virtual ~A() {}
};

class B : public A {
  public:
    virtual ~B() {}
};

int main(int __unused fc, char **argv) {
  A *a = new B;
  B *b = dynamic_cast<B *>(a);
  return 0;
}

//the dynamic_cast operator it let us know if the object ptr or reference can trosform to the type we want,
//if can it return the pointer or reference to the object, 
//if not it return a null pointer or throw a bad_cast exception if we use reference

//static_cast it can cast between pointers and references of related classes, or between numeric types


//todo : check the errors from https://rphlr.github.io/42-Evals/Cursus/CPP06/