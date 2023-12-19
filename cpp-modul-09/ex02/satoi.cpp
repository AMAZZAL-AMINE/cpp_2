#include "main.h"

long satoi(std::string nbr) {
  long result = 0;
  int isMis = 1;
  int count = 0;
  if (nbr[0] == '-') {
    isMis = -1;
    count++;
  }
  while (count < static_cast<int>(nbr.length())) {
    if (!std::isdigit(nbr[count]))
      throw std::string("Error : bad input");
    result = (result * 10) + nbr[count] - 48;
    count++;
  }
  return result * isMis;
}