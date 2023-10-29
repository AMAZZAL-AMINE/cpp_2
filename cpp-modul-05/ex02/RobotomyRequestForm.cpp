/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 20:23:37 by mamazzal          #+#    #+#             */
/*   Updated: 2023/10/29 21:17:31 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 20:18:01 by mamazzal          #+#    #+#             */
/*   Updated: 2023/10/29 20:22:54 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

//* ORTHODOX CANONICAL FORM *//

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm & copy) : AForm(copy) {
  *this = copy;
}

void RobotomyRequestForm::operator=(RobotomyRequestForm & op) {
  this->target = op.target;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

//* END ORTHODOX CANONICAL FORM *//

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45) {
  this->target = target;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
  if (biro.grade > this->getGradeToExecute() || !this->getIsSigned())
    throw AForm::GradeTooLowException();
  std::cout << this->target << " has been robotomized successfully 50% of the time." << std::endl;
}
