/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 15:22:38 by mamazzal          #+#    #+#             */
/*   Updated: 2023/10/29 21:02:43 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "main.h"
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
  private :
    const std::string name;
    bool is_signed;
    const int gradeToSign;
    const int gradeToExecute;
  public :
    /** ORTHODOX CANONICAL FORM*/
    AForm();
    AForm(AForm const & src);
    void operator=(AForm const & rhs);
    ~AForm();
    /** ----- END ORTHODOX -------- */

    AForm(std::string name, int gradeToSign, int gradeToExecute);
    std::string getName();
    int getGradeToSign() ;
    int getGradeToExecute();
    bool getIsSigned();
    void beSigned(Bureaucrat & bureaucrat) ;
    virtual execute(Bureaucrat const & executor) const = 0;
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

std::ostream & operator<<(std::ostream & o, AForm const & rhs);

#endif