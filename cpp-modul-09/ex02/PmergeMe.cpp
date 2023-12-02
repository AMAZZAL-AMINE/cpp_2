#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(PmergeMe const &src){ *this = src;}
PmergeMe & PmergeMe::operator=(PmergeMe const __unused &src){return *this;}
PmergeMe::~PmergeMe() {}


void PmergeMe::pushArg(std::string args) {
  this->stack.push_back(satoi(args));
}

void PmergeMe::displayStackBefor() {
  std::vector<int>::iterator start = this->stack.begin();
  std::cout << "Befor : ";
  while (start != this->stack.end()) {
    std::cout << *start << " ";
    start++;
  }
  std::cout << std::endl;
}

void PmergeMe::checkArgment(std::string & arg) {
  int i = -1;
  while (++i < static_cast<int>(arg.length())) {
    if (!std::isdigit(arg[i]))
      throw std::string("Error : non digit not allowed here!");
  }
}


void PmergeMe::gropStackIntoPairs() {
  std::vector<int>::iterator start = this->stack.begin();
  // std::vector<int>::iterator end = this->stack.end();
  std::vector<int> tmp;
  int i = 0;
  while (i < static_cast<int>(this->stack.size()) / 2) {
    tmp.push_back(*start);
    start++;
    tmp.push_back(*start);
    this->pairs.push_back(tmp);
    tmp.clear();
    start++;
    i++;
  }
}

void PmergeMe::sortEachPairs() {
  std::vector<std::vector<int> >::iterator startParent = this->pairs.begin();
  while (startParent != this->pairs.end()) {
    std::vector<int> & ff = *startParent;
    std::sort(ff.begin(), ff.end());
    std::reverse(ff.begin(), ff.end());
    startParent++;
  }
  this->sortAllPairs(this->pairs);
}

void PmergeMe::sortAllPairs(std::vector<std::vector<int> > & pair, size_t index) {
  //recursive sort the pair by the second element in the pair
    if (index + 1 == pair.size())
      return;
    if (pair[index][1] > pair[index + 1][1])
      std::swap(pair[index], pair[index + 1]);
    this->sortAllPairs(this->pairs, index + 1);
}




void PmergeMe::displayPairs() {
  std::vector<std::vector<int> >::iterator startParent = this->pairs.begin();
  while (startParent != this->pairs.end()) {
    std::vector<int> ff = *startParent;
    std::vector<int>::iterator start = ff.begin();
    std::cout << "PAIR : ";
    while (start != ff.end()) {
      std::cout << *start << " ";
      start++;
    }
    std::cout << "\n";
    startParent++;
  }
}
