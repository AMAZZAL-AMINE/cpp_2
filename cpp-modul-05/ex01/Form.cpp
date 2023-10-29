/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 15:38:16 by mamazzal          #+#    #+#             */
/*   Updated: 2023/10/29 16:15:51 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/** ORTHODOX CANONICAL FORM*/
Form::Form() : name("default"), gradeToSign(150), gradeToExecute(150) {
  this->is_signed = false;
}

Form::Form(Form const & src) : name(src.name), gradeToSign(src.gradeToSign), gradeToExecute(src.gradeToExecute) {
  *this = src;
}

void Form::operator=(Form const & rhs) {
  this->is_signed = rhs.is_signed;
}

Form::~Form() {}

/** ----- END ORTHODOX -------- */

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
  this->is_signed = false;
  if (this->gradeToSign > 150 || this->gradeToExecute > 150) {
    throw Form::GradeTooHighException();
  } else if (this->gradeToSign < 1 || this->gradeToExecute < 1) {
    throw Form::GradeTooLowException();
  }
}

std::string Form::getName() {
  return this->name;
}

int  Form::getGradeToSign() {
  return this->gradeToSign;
}

int  Form::getGradeToExecute() {
  return this->gradeToExecute;
}

bool Form::getIsSigned() {
  return this->is_signed;
}

void Form::beSigned(Bureaucrat & bureaucrat) {
  if (bureaucrat.getGrade() > this->gradeToSign) {
    throw Form::GradeTooLowException();
  } else {
    this->is_signed = true;
  }
}


std::ostream & operator<<(std::ostream & o, Form  __unused const & rhs) {
  return o;
}