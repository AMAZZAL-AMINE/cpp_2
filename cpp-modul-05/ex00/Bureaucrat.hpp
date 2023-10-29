/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 11:44:41 by mamazzal          #+#    #+#             */
/*   Updated: 2023/10/29 13:01:33 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "main.h"

class Bureaucrat {
  private :
    std::string name;
    int grade;
  public :
    Bureaucrat();
    Bureaucrat(Bureaucrat const & src);
    void operator=(Bureaucrat const & rhs);
    ~Bureaucrat();

    Bureaucrat(std::string name, int grade);
    std::string getName() const;
    int getGrade() const;
    void incrementGrade();
    void decrementGrade();
    class GradeTooHighException : public std::exception {
      const char *what () const throw () {
        return "nah, you try a biger grade";
      }
    };

    class GradeTooLowException : public std::exception {
      const char *what () const throw () {
       return "nah, you try a lower  grade";
      }
    };
};

std::ostream & operator<<(std::ostream & os, Bureaucrat & biro);

#endif