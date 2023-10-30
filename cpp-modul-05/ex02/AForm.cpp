/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 15:38:16 by mamazzal          #+#    #+#             */
/*   Updated: 2023/10/30 10:48:03 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/** ORTHODOX CANONICAL FORM*/
AForm::AForm() : name("default"), gradeToSign(150), gradeToExecute(150) {
  this->is_signed = false;
}

AForm::AForm(AForm const & src) : name(src.name), gradeToSign(src.gradeToSign), gradeToExecute(src.gradeToExecute) {
  *this = src;
}

void AForm::operator=(AForm const & rhs) {
  this->is_signed = rhs.is_signed;
}

AForm::~AForm() {}

/** ----- END ORTHODOX -------- */

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
  this->is_signed = false;
  if (this->gradeToSign > 150 || this->gradeToExecute > 150) {
    throw AForm::GradeTooHighException();
  } else if (this->gradeToSign < 1 || this->gradeToExecute < 1) {
    throw AForm::GradeTooLowException();
  }
}

std::string AForm::getName()  const {
  return this->name;
}

int  AForm::getGradeToSign() const {
  return this->gradeToSign;
}

int  AForm::getGradeToExecute() const {
  return this->gradeToExecute;
}

bool AForm::getIsSigned() const {
  return this->is_signed;
}

void AForm::beSigned(Bureaucrat & bureaucrat) {
  if (bureaucrat.getGrade() > this->gradeToSign) {
    throw AForm::GradeTooLowException();
  } else {
    this->is_signed = true;
  }
}


std::ostream & operator<<(std::ostream & o, AForm  __unused const & rhs) {
  return o;
}
