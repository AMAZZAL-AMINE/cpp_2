#ifndef RPN_HPP
#define RPN_HPP

#include "main.h"

class RPN {
    private :
      std::string  ArgmentsStr;
      int searchAmoungData(std::string, int);
      int checkArgmnets();
      std::stack<int> stackList;
      void pushNumbers();
      int getCalculAndInsert(int nbr1, int nbr2, int flag) ;
    public :
      RPN();
      RPN(RPN const &src);
      RPN &operator=(RPN const &src);
      ~RPN();
      void setArgments(std::string argments);
      void getResult() const;
  };

#endif