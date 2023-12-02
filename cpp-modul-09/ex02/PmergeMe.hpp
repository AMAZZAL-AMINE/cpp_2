#ifndef PmergeMe_HPP
#define PmergeMe_HPP

#include "main.h"

class PmergeMe {
    private :
      std::string args;
      std::vector<int> stack;
      std::vector<std::vector<int> > pairs;
      // creat main chain and pend
      
      
    public :
      PmergeMe();
      PmergeMe(PmergeMe const &src);
      PmergeMe &operator=(PmergeMe const &src);
      ~PmergeMe();
      void pushArg(std::string args);
      void displayStackBefor();
      void checkArgment(std::string & arg);
      void gropStackIntoPairs();
      void displayPairs();
      void sortEachPairs();
      void sortAllPairs(std::vector<std::vector<int> >& pairs, size_t index = 0);
  };

#endif