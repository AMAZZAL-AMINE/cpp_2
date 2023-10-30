/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:20:49 by mamazzal          #+#    #+#             */
/*   Updated: 2023/10/30 11:29:23 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "main.h"

class Intern {
  private :
  public :
    Intern();
    Intern(Intern const & src);
    void operator=(Intern const & rhs);
    ~Intern();

    AForm *makeForm(std::string formName, std::string target);
    class UnknownFormException : public std::exception {
      const char *what () const throw () {
        return "Unknown Form";
      }
    };
};

#endif