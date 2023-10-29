/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 20:18:01 by mamazzal          #+#    #+#             */
/*   Updated: 2023/10/29 21:06:37 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

//* ORTHODOX CANONICAL FORM *//

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm & copy) : AForm(copy) {
  *this = copy;
}

void ShrubberyCreationForm::operator=(ShrubberyCreationForm & op) {
  this->target = op.target;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

//* END ORTHODOX CANONICAL FORM *//

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137) {
  this->target = target;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
  if (biro.getGrade() > this->getGradeToExecute() || !this->getIsSigned())
    throw AForm::GradeTooLowException();
  std::ofstream file;
  file.open(this->target + "_shrubbery");

  file << "      /\\      " << std::endl;
  file << "     /\\*\\     " << std::endl;
  file << "    /\\O\\*\\    " << std::endl;
  file << "   /*/\\/\\/\\   " << std::endl;
  file << "  /\\O\\/\\*\\/\\  " << std::endl;
  file << " /\\*\\/\\*\\/\\/\\ " << std::endl;
  file << "/\\O\\/\\*\\/\\/O/\\\\" << std::endl;
  file << "      ||      " << std::endl;
  file << "      ||      " << std::endl;
  file << "      ||      " << std::endl;
  file.close();
}