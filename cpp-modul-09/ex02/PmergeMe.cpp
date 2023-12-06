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

void PmergeMe::start() {
  if (this->stack.size() % 2 == 0)
    this->repair.push_back(this->stack.back());
}
