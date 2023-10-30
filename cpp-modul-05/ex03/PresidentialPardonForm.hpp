/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 21:18:45 by mamazzal          #+#    #+#             */
/*   Updated: 2023/10/30 10:32:48 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "main.h"

class PresidentialPardonForm : public AForm {
  private :
    std::string target;
  public :
  //* ORTHODOX CANONICAL FORM *//
    PresidentialPardonForm();
    PresidentialPardonForm(PresidentialPardonForm & copy);
    void operator=(PresidentialPardonForm & op);
    ~PresidentialPardonForm();
  //* END ORTHODOX CANONICAL FORM *//
  PresidentialPardonForm(std::string target);
  void execute(Bureaucrat const & executor) const;
};

#endif