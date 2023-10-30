/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 21:18:55 by mamazzal          #+#    #+#             */
/*   Updated: 2023/10/30 13:53:04 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm & copy) : AForm("PresidentialPardonForm", 25, 5) {
  *this = copy;
}

void PresidentialPardonForm::operator=(PresidentialPardonForm & op) {
  this->target = op.target;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

/** ___________________________________________________________________ */

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5) {
  this->target = target;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
  if (executor.getGrade() > this->getGradeToExecute() || !this->getIsSigned())
    throw AForm::GradeTooLowException();
  std::cout << this->target << "has been pardoned by Zaphod Beeblebrox." << std::endl;
}
