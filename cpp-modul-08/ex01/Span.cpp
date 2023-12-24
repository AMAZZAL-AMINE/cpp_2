/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 21:25:01 by mamazzal          #+#    #+#             */
/*   Updated: 2023/12/22 11:35:10 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() {
  this->max = 10;
}
Span::Span(Span const &src){
  *this = src;
}

Span & Span::operator=(Span const &src){
  if (this != &src) {
    this->max = src.max;
    this->integers = src.integers;
  }
  return *this;
}

Span::~Span() {}

Span::Span(unsigned int N) : max(N) {
  this->integers.reserve(this->max);
}

void Span::addNumber(int nbr) {
  if (this->integers.size() < this->max) {
    this->integers.push_back(nbr);
  }else {
    throw std::string("custom sigfault, the stack is full");
  }
}

int Span::shortestSpan() {

  if (this->integers.size() < 2) {
    throw std::string("cannot get a span of stack that have <= 1 in size");
  }
  std::vector<int> tmp = this->integers;
  std::sort(tmp.begin(), tmp.end());
  std::reverse(tmp.begin(), tmp.end());
  std::vector<int>::iterator current = tmp.begin();
  std::vector<int>::iterator next = tmp.begin() + 1;
  int result = *current - *next;
  while (current != tmp.end()) {
    if ((*current - *next) < result) {
      result = *current - *next;
    }
    next += 1;
    current++;
  }
  return result;
}

int Span::longestSpan() {
  if (this->integers.size() < 2) {
    throw std::string("cannot get a span of stack that have <= 1 in size");
  }
  std::vector<int>::iterator max  = std::max_element(this->integers.begin(), this->integers.end());
  std::vector<int>::iterator min = std::min_element(this->integers.begin(), this->integers.end());
  return *max - *min;
}
