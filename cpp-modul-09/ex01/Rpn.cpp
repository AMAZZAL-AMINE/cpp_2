#include "RPN.hpp"

RPN::RPN() {}
RPN::RPN(RPN const __unused &src){
  *this = src;
}
RPN & RPN::operator=(RPN const __unused &src){
  if (this != &src) {
    this->ArgmentsStr = src.ArgmentsStr;
    this->stackList = src.stackList;
  }
  return *this;
}
RPN::~RPN() {}


int RPN::searchAmoungData(std::string arg, int c) {
  size_t i = -1;
  while (++i < arg.length() )
    if (c == arg[i])
      return 1;
  return 0;
}

int RPN::checkArgmnets() {
  size_t count = -1;

  if (this->ArgmentsStr.empty())
    throw std::string("Error : empty Argments");
  if (this->ArgmentsStr.length() <= 2)
    throw std::string("Error : Not enough Argments");
  while (++count < this->ArgmentsStr.length()) {
    if (!this->searchAmoungData("0123456789 +/*-", this->ArgmentsStr[count]))
      throw std::string("Error : INVALID ARGMENTS");
    if (std::isdigit(this->ArgmentsStr[count]) && this->ArgmentsStr[count + 1] && std::isdigit(this->ArgmentsStr[count + 1]))
      throw std::string("Error : Numbers can be only from 0 to 9");
  }
  return 0;
}

int RPN::getCalculAndInsert(int nbr1, int nbr2, int flag) {
  switch (flag)
  {
    case '-' :
      return nbr1 - nbr2;
    case '+' :
      return nbr1 + nbr2;
    case '/' :
      return nbr1 / nbr2;
    case '*' :
      return nbr1 * nbr2;
    default:
      return 0;
  }
}

void RPN::pushNumbers() {
  size_t count = -1;

  count = -1;
  while (++count <  this->ArgmentsStr.length()) {
    if (std::isdigit(this->ArgmentsStr[count]))
      this->stackList.push(this->ArgmentsStr[count] - 48);
    else if (this->ArgmentsStr[count] == '-' || this->ArgmentsStr[count] == '+' || this->ArgmentsStr[count] == '/' || this->ArgmentsStr[count] == '*') {
        if (this->stackList.size() < 2)
          throw std::string("Error : Not enough numbers");
        int nbr2 = this->stackList.top();
        this->stackList.pop();
        int nbr1 = this->stackList.top();
        this->stackList.pop();
        this->stackList.push(getCalculAndInsert(nbr1, nbr2, this->ArgmentsStr[count]));
    }
  }
}

void RPN::setArgments(std::string argments) {
  this->ArgmentsStr = argments;
  this->checkArgmnets();
  this->pushNumbers();
}

void RPN::getResult() const {
  std::cout << "RESULT : " << this->stackList.top() << std::endl;
}