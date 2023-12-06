#include "PmergeMe.hpp"

int countComparison;

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


void PmergeMe::mergeDivide(std::vector<int> & stack) {
  //divide stack/n;
  int stackSize = stack.size();
  if (stackSize < 2)
    return ;
  std::vector<int>::iterator start = stack.begin();
  int midl = stackSize / 2;
  int count = 0;
  
  std::vector<int> left;
  std::vector<int> right;

  while (count < midl) {
    left.push_back(*start);
    start++;
    count++;
  }
  count = midl;
  while (count < stackSize) {
    right.push_back(*start);
    start++;
    count++;
  }
  this->mergeDivide(left);
  this->mergeDivide(right);
  merge(stack, left, right);
}


void PmergeMe::displayPairs() {
  std::vector<int>::iterator start = this->stack.begin();

  while (start != this->stack.end()) {
    std::cout << *start << " ";
    start++;
  }
  std::cout << "\n";
}

void PmergeMe::merge(std::vector<int> &result,  std::vector<int> &left,  std::vector<int> &right) {
  std::vector<int> temp;
  std::vector<int>::iterator leftIter = left.begin();
  std::vector<int>::iterator rightIter = right.begin();

  while (leftIter != left.end() && rightIter != right.end()) {
    if (*leftIter < *rightIter) {
      countComparison++;
      temp.push_back(*leftIter);
      leftIter++;
    } else {
      temp.push_back(*rightIter);
      rightIter++;
    }
  }

  // Append the remaining elements
  temp.insert(temp.end(), leftIter, left.end());
  temp.insert(temp.end(), rightIter, right.end());

  // Copy the merged result back to the original vector
  result = temp;
}

void PmergeMe::start() {
  std::cout << "Befor : ";
  this->displayPairs();
  this->mergeDivide(this->stack);
  std::cout << "After : ";
  this->displayPairs();
  std::cout << "\n";
  std::cout << "COMPARIZON : " << countComparison << std::endl;
}
