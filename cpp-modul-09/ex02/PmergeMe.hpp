#ifndef PmergeMe_HPP
#define PmergeMe_HPP

#include "main.h"

class PmergeMe {
    private :
      std::vector<int> data;
      std::deque<int> dataDeque;
    public :
      PmergeMe();
      PmergeMe(PmergeMe const &src);
      PmergeMe &operator=(PmergeMe const &src);
      ~PmergeMe();
      void setNumbers(std::string str);
      void displayNumbers();
      void merge();
      void mergeAndSortPairsVector(std::vector<int> & vec, size_t size);
      void mergeAndSortPairsDeque(std::deque<int> & vec, size_t size);
  };

#endif