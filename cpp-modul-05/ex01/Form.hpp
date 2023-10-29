/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 15:22:38 by mamazzal          #+#    #+#             */
/*   Updated: 2023/10/29 16:14:37 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "main.h"
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
  private :
    const std::string name;
    bool is_signed;
    const int gradeToSign;
    const int gradeToExecute;
  public :
    /** ORTHODOX CANONICAL FORM*/
    Form();
    Form(Form const & src);
    void operator=(Form const & rhs);
    ~Form();
    /** ----- END ORTHODOX -------- */

    Form(std::string name, int gradeToSign, int gradeToExecute);
    std::string getName();
    int getGradeToSign();
    int getGradeToExecute();
    bool getIsSigned();
    void beSigned(Bureaucrat & bureaucrat);
    class GradeTooHighException : public std::exception {
      const char* what() const throw () {
        return "Grade too high";
      }
    };

    class GradeTooLowException : public std::exception {
      const char* what() const throw () {
        return "Grade too low";
      }
    };
};

std::ostream & operator<<(std::ostream & o, Form const & rhs);

#endif