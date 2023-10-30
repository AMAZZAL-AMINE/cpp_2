/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:31:18 by mamazzal          #+#    #+#             */
/*   Updated: 2023/10/30 13:34:38 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

Intern::Intern() {}

Intern::Intern(Intern const & src) {
  *this = src;
}

void Intern::operator=(Intern const & rhs) {
  (void)rhs;
}

Intern::~Intern() {}

/** _______________________ CLASS CONTENT ________________________  */

AForm *Intern::makeForm(std::string formName, std::string target) {
  std::string  names[] = {"robotomy request", "presidential pardon", "shrubbery creation"};
  int  i = 0;
  int find = -1;
  while (i < 3) {
    if (names[i] == formName) {
      find = i;
      break;
    }
    i++;
  }
  switch (find)
  {
    case 0 :
      return new RobotomyRequestForm(target);
    case 1 :
      return new PresidentialPardonForm(target);
    case 2 :
      return new ShrubberyCreationForm(target);
    default:
      break;
  }
  throw Intern::UnknownFormException();
}
