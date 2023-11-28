#include "RPN.hpp"

RPN::RPN() {}
RPN::RPN(RPN const __unused &src){}
RPN & RPN::operator=(RPN const __unused &src){return *this;}
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

  while (++count < this->ArgmentsStr.length())
    if (!this->searchAmoungData("0123456789 +/*-", this->ArgmentsStr[count]))
      return 1;
  return 0;
}

void RPN::pushTopTo(std::stack<int> &  newStack, int flag) {
  int top = this->stackList.top();
  this->stackList.pop();
  int top2 = this->stackList.top();
  this->stackList.pop();
  switch (flag)
  {
  case '-' :
    newStack.push(top - top2);
    break;
  case '+' :
    newStack.push(top + top2);
    break;
  case '/' :
    newStack.push(top / top2);
    break;
  case '*' :
    newStack.push(top * top2);
    break;
  default:
    break;
  }
}

void RPN::getCalculAndInsert(std::stack<int> &  newStack, int flag) {
  int top = this->stackList.top();
  this->stackList.pop();
  int top2 = newStack.top();
  newStack.pop();

  switch (flag)
  {
    case '-' :
      newStack.push(top2 - top);
      break;
    case '+' :
      newStack.push(top2 + top);
      break;
    case '/' :
      newStack.push(top2 / top);
      break;
    case '*' :
      newStack.push(top2 * top);
      break;
    default:
      break;
  }
}

void RPN::pushNumbers() {
  size_t count = -1;
  std::stack<int> tmpStack;
  while (++count <  this->ArgmentsStr.length()) {
    if (std::isdigit(this->ArgmentsStr[count]))
      tmpStack.push(this->ArgmentsStr[count] - 48);
  }

  while (!tmpStack.empty()) {
    this->stackList.push(tmpStack.top());
    tmpStack.pop();
  }

  std::stack<int> newStack;
  count = -1;
  while (++count <  this->ArgmentsStr.length()) {
    if (this->ArgmentsStr[count] == '-' || this->ArgmentsStr[count] == '+' || this->ArgmentsStr[count] == '/' || this->ArgmentsStr[count] == '*') {
      this->pushTopTo(newStack, this->ArgmentsStr[count]);
      break;
    }
    if (newStack.size() == 1)
      break;
  }
  while (++count <  this->ArgmentsStr.length()){
    if (this->ArgmentsStr[count] == '-')
      this->getCalculAndInsert(newStack, '-');
    else if (this->ArgmentsStr[count] == '+')
      this->getCalculAndInsert(newStack, '+');
    else if (this->ArgmentsStr[count] == '/')
      this->getCalculAndInsert(newStack, '/');
    else if (this->ArgmentsStr[count] == '*')
      this->getCalculAndInsert(newStack, '*');
    else if (this->stackList.size() == 0)
      break;
  }
  std::cout << "POLISH NOTATION RESULT : " << newStack.top() << std::endl;
}

void RPN::setArgments(std::string argments) {
  this->ArgmentsStr = argments;
  if (this->checkArgmnets())
    throw std::string("Error : INVALID ARGMENTS");
  this->pushNumbers();
}

void RPN::display() const {
  // this->pushNumbers();
}
 