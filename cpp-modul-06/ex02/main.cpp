/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:07:18 by mamazzal          #+#    #+#             */
/*   Updated: 2023/11/03 17:48:14 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

Base * generate(void) {
  int randomNbrs = time(0) % 3;
  srand(randomNbrs);
  switch (randomNbrs)
  {
    case 0 :
      return new A;
    case 1 : 
      return new B;
    default:
      return new C;
      break;
  }
}

void identify(Base* p) {
  if (dynamic_cast<A*>(p))
    std::cout << "Type of p is : A" << std::endl;
  else if (dynamic_cast<B*>(p))
    std::cout << "Type of p is : B" << std::endl;
  else if (dynamic_cast<C*>(p))
    std::cout << "Type of p is : C" << std::endl;
}

void identify(Base& p) {
  try {
    A __unused & a = dynamic_cast<A&>(p);
    std::cout << "Reference Of typr p is A" << std::endl;
  }
  catch(const std::exception& e) {
    try {
      B __unused & b = dynamic_cast<B&>(p);
      std::cout << "Reference Of typr p is B" << std::endl;
    }
    catch(const std::exception& e) {
      try {
        C __unused & c = dynamic_cast<C&>(p);
        std::cout << "Reference Of typr p is C" << std::endl;
      }
      catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
      }
    }
  }
}

int main(void) {
  Base *p = generate();
  identify(*p); //reference
  identify(p); //pointer
  return 0;
}
