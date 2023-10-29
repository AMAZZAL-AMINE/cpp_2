/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 17:56:26 by mamazzal          #+#    #+#             */
/*   Updated: 2023/10/29 21:03:00 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  ROBOTOMYREQUESTFORM_HPP
# define  ROBOTOMYREQUESTFORM_HPP

#include "main.h"

class RobotomyRequestForm : public AForm {
  private :
    std::string target;
  public :
  //* ORTHODOX CANONICAL FORM *//
    RobotomyRequestForm();
    RobotomyRequestForm(RobotomyRequestForm & copy);
    void operator=(RobotomyRequestForm & op);
    ~RobotomyRequestForm();
  //* END ORTHODOX CANONICAL FORM *//
    RobotomyRequestForm(std::string target);
    void execute(Bureaucrat const & executor) const;
};

#endif