#ifndef SPAN_HPP
#define SPAN_HPP

#include "main.h"

class Span {
    private :
      unsigned int max;
      std::vector<int> integers;
    public :
      Span();
      Span(Span const &src);
      Span &operator=(Span const &src);
      ~Span();
      
      Span(unsigned int N);
      void addNumber(int N);
      int shortestSpan();
      int longestSpan();

  };

#endif