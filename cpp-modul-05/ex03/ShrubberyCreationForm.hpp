/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 17:56:26 by mamazzal          #+#    #+#             */
/*   Updated: 2023/10/29 21:02:54 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "main.h"

class ShrubberyCreationForm : public AForm {
  private :
    std::string target;
  public :
  //* ORTHODOX CANONICAL FORM *//
    ShrubberyCreationForm();
    ShrubberyCreationForm(ShrubberyCreationForm & copy);
    void operator=(ShrubberyCreationForm & op);
    ~ShrubberyCreationForm();
  //* END ORTHODOX CANONICAL FORM *//
  ShrubberyCreationForm(std::string target);
  void execute(Bureaucrat const & executor) const;
};

#endif