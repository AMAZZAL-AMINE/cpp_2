/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 22:05:00 by mamazzal          #+#    #+#             */
/*   Updated: 2023/10/30 11:16:22 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
/**
 * Orthodox Canonical Form
*/
Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat(Bureaucrat const & src) {
  *this = src;
}

void Bureaucrat::operator=(Bureaucrat const & rhs) {
  this->name = rhs.getName();
  this->grade = rhs.getGrade();
}

Bureaucrat::~Bureaucrat() {}

/**
 * end of Orthodox Canonical Form
 */


/** _______________________ CLASS CONTENT ________________________  */

std::string Bureaucrat::getName() const {
  return this->name;
}

int Bureaucrat::getGrade() const {
  return this->grade;
}

void Bureaucrat::incrementGrade() {
  this->grade -= 1;
}
void Bureaucrat::decrementGrade() {
  this->grade += 1;
}

Bureaucrat::Bureaucrat(std::string name, int grade) {
  this->name = name;
  this->grade = grade;
  if (this->grade > 150) {
    throw Bureaucrat::GradeTooHighException();
  }else if (this->grade < 1) {
    throw Bureaucrat::GradeTooLowException();
  }
}

void Bureaucrat::signForm(AForm & form ) const {
  if (form.getIsSigned()) {
    std::cout << this->getName() << " signed " << form.getName();
  }else {
    std::cout << this->getName() << " couldn’t sign " << form.getName() << " because " << this->getName() << " grade is too low";
  }
}

std::ostream & operator<<(std::ostream & os, Bureaucrat & biro) {
  os << biro.getName() << ", bureaucrat grade " << biro.getGrade();
  return os;
}


void Bureaucrat::executeForm(AForm const & form) const {
  if (form.getIsSigned()) {
    std::cout << this->getName() << " executes " << form.getName()<< std::endl;
  }else {
    std::cout << this->getName() << " couldn’t execute " << form.getName() << " because " << this->getName() << " grade is too low" << std::endl;
  }
}
