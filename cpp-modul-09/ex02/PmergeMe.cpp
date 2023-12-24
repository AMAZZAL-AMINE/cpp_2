#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(PmergeMe const &src){ *this = src;}
PmergeMe & PmergeMe::operator=(PmergeMe const __unused &src){return *this;}
PmergeMe::~PmergeMe() {}


void PmergeMe::setNumbers(std::string str) {
  int count = 0;
  int result = 0;
  int mes = 1;
  if (str[0] == '-' || str[0] == '+') {
    if (str[0] == '-')
      mes = -1;
    count++;
  }
  while (str[count]) {
    if (!std::isdigit(str[count]))
      throw PmergeMe::badInputException();
    result = (result * 10) + (str[count] - 48);
    count++;
  }
  this->data.push_back(result * mes);
  this->dataDeque.push_back(result * mes);
}

void PmergeMe::displayNumbers() {
  for(std::vector<int>::iterator start = this->data.begin(); start < this->data.end(); start++) {
    std::cout << *start << " ";
  }
  std::cout << ";\n";
}

void PmergeMe::mergeAndSortPairsVector(std::vector<int> & vec, size_t size) {
  if (size * 2 > vec.size()) return;
  std::vector<int> tmp;

  if (vec.size() % (size * 2) != 0) {
    tmp.insert(tmp.begin(), vec.end() - size, vec.end());
    vec.erase(vec.end() - size, vec.end());
  }

  std::vector<std::vector<int> > pairs;
  for (size_t i = 0; i < vec.size(); i += size * 2) {
    std::vector<int> firs, secnd, resu;
    for (size_t j = i; j < i + size; j++)
      firs.push_back(vec[j]);
    for (size_t j = i + size; j < i + (size * 2); j++)
      secnd.push_back(vec[j]);
    if (firs.back() > secnd.back()) {
      std::swap(firs, secnd);
    }
    comparizonCound++;
    for (size_t j = 0; j < size; j++)
      resu.push_back(firs[j]);
    for (size_t j = 0; j < size; j++)
      resu.push_back(secnd[j]);
    pairs.push_back(resu);
  }
  vec.clear();
  for (size_t i = 0; i < pairs.size(); i++) {
    std::vector<int> & subvec = pairs[i];
    for (size_t j = 0; j < subvec.size(); j++)
      vec.push_back(subvec[j]);
  }
  mergeAndSortPairsVector(vec, size * 2);

  //split the collection to parts
  std::vector<std::vector<int> > halfers;
  for(size_t count = 0; count < vec.size(); count += size * 2) {
    std::vector<int> f,s;
    for(size_t i = count; i < count + size; i++)
      f.push_back(vec[i]);
    for(size_t i = count + size; i < count + (size * 2); i++)
      s.push_back(vec[i]);
    halfers.push_back(f);
    halfers.push_back(s);
  }

  std::vector<std::vector<int> > mainChine;
  std::vector<std::vector<int> > pendchine;
  //push to pend and mainchine
  std::vector<std::vector<int> >::iterator halfStart = halfers.begin();
  int index = 0;
  for(; halfStart != halfers.end(); halfStart++) {
    if (index % 2 != 0)
        mainChine.push_back(*halfStart);
    else
      pendchine.push_back(*halfStart);
    index++;
  }
  //jacobsthal generator 
  std::vector<int> penTmp;
  std::vector<int> __unused jacobsthal = jacobsthalGenerator(pendchine.size());
  if (tmp.size() > 0) 
    pendchine.push_back(tmp);
//push the remain to the pendchin
  size_t i = 0;
  int amin = 0;
  size_t prev = 0;
  while (i < jacobsthal.size()) {
    size_t jacob = jacobsthal[i];

    while (jacob > prev) {
      if (jacob - 1 < pendchine.size()) {
        if (jacob - 1 == 0) {
          mainChine.insert(mainChine.begin(), pendchine[0]);
          amin++;
        }
        else {
          std::vector<int> original = pendchine[jacob - 1];
          std::vector<std::vector<int> >::iterator position = lower_bound(mainChine.begin(), mainChine.begin() + jacob + amin - 1, original, compare);
          mainChine.insert(position, original);
          amin++;
        }
        jacob--;
      }
      else
        jacob = pendchine.size();
    }
    prev = jacobsthal[i];
    i++;
  }
  vec.clear();
  //push back the mainchine toe our collection
  if (mainChine.size() > 0) {
    for(std::vector<std::vector<int> >::iterator start = mainChine.begin(); start != mainChine.end(); start++) {
      std::vector<int> mainTemp = *start;
      for(size_t i = 0; i < mainTemp.size(); i++)
        vec.push_back(mainTemp[i]);
    }
  }
}

//container deque
void PmergeMe::mergeAndSortPairsDeque(std::deque<int> & deq, size_t size) {
  if (size * 2 > deq.size()) return;

  std::deque<int> tmp;
  if (deq.size() % (size * 2) != 0) {
    tmp.insert(tmp.begin(), deq.end() - size, deq.end());
    deq.erase(deq.end() - size, deq.end());
  }

  std::deque<std::deque<int> > pairs;
  for (size_t i = 0; i < deq.size(); i += size * 2) {
    std::deque<int> firs, secnd, resu;
    for (size_t j = i; j < i + size; j++)
      firs.push_back(deq[j]);
    for (size_t j = i + size; j < i + (size * 2); j++)
      secnd.push_back(deq[j]);
    if (firs.back() > secnd.back()) {
      std::swap(firs, secnd);
    }
    comparizonCoundDeque++;
    for (size_t j = 0; j < size; j++)
      resu.push_back(firs[j]);
    for (size_t j = 0; j < size; j++)
      resu.push_back(secnd[j]);
    pairs.push_back(resu);
  }
  deq.clear();
  for (size_t i = 0; i < pairs.size(); i++) {
    std::deque<int> & subvec = pairs[i];
    for (size_t j = 0; j < subvec.size(); j++)
      deq.push_back(subvec[j]);
  }
  mergeAndSortPairsDeque(deq, size * 2);

  //split the collection to parts
  std::deque<std::deque<int> > halfers;
  for(size_t count = 0; count < deq.size(); count += size * 2) {
    std::deque<int> f,s;
    for(size_t i = count; i < count + size; i++)
      f.push_back(deq[i]);
    for(size_t i = count + size; i < count + (size * 2); i++)
      s.push_back(deq[i]);
    halfers.push_back(f);
    halfers.push_back(s);
  }

  std::deque<std::deque<int> > mainChine;
  std::deque<std::deque<int> > pendchine;
  //push to pend and mainchine
  std::deque<std::deque<int> >::iterator halfStart = halfers.begin();
  int index = 0;
  for(; halfStart != halfers.end(); halfStart++) {
    if (index % 2 != 0)
        mainChine.push_back(*halfStart);
    else
      pendchine.push_back(*halfStart);
    index++;
  }
  //jacobsthal generator 
  std::deque<int> penTmp;
  std::deque<int> __unused jacobsthal = jacobsthalGeneratorDeque(pendchine.size());
  if (tmp.size() > 0) 
    pendchine.push_back(tmp);
//push the remain to the pendchin
  size_t i = 0;
  int amin = 0;
  size_t prev = 0;
  while (i < jacobsthal.size()) {
    size_t jacob = jacobsthal[i];

    while (jacob > prev) {
      if (jacob - 1 < pendchine.size()) {
        if (jacob - 1 == 0) {
          mainChine.insert(mainChine.begin(), pendchine[0]);
          amin++;
        }
        else {
          std::deque<int> original = pendchine[jacob - 1];
          std::deque<std::deque<int> >::iterator position = lower_bound(mainChine.begin(), mainChine.begin() + jacob + amin - 1, original, compareDeque);
          mainChine.insert(position, original);
          amin++;
        }
        jacob--;
      }
      else
        jacob = pendchine.size();
    }
    prev = jacobsthal[i];
    i++;
  }
  deq.clear();
  //push back the mainchine toe our collection
  if (mainChine.size() > 0) {
    for(std::deque<std::deque<int> >::iterator start = mainChine.begin(); start != mainChine.end(); start++) {
      std::deque<int> mainTemp = *start;
      for(size_t i = 0; i < mainTemp.size(); i++)
        deq.push_back(mainTemp[i]);
    }
  }
}


void PmergeMe::merge() {
  std::cout << "Before: ";
  this->displayNumbers();
  double VectorStart = std::clock();
  mergeAndSortPairsVector(this->data, 1);
  std::cout << "After: ";
  this->displayNumbers();
  std::cout << "\n";
  std::cout << "Time to process a range of " << this->data.size() << " elements with std::vecotr :" << std::fixed << static_cast<double>(std::clock() - VectorStart) / CLOCKS_PER_SEC << " us\n";
  VectorStart = std::clock();
  mergeAndSortPairsDeque(this->dataDeque, 1);
  std::cout << "Time to process a range of " << this->data.size() << " elements with std::vecotr : " << std::fixed << static_cast<double>(std::clock() - VectorStart) / CLOCKS_PER_SEC << " us\n";
}