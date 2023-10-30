/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 11:35:39 by mamazzal          #+#    #+#             */
/*   Updated: 2023/10/30 11:15:51 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int main() {
  try {
    Bureaucrat biro("MBABO", 2);
    biro.incrementGrade();
    ShrubberyCreationForm form("home");
    RobotomyRequestForm form2("manzil");
    form.beSigned(biro);
    form.execute(biro);
    form2.beSigned(biro);
    form2.execute(biro);
    std::cout << biro << std::endl;
    biro.executeForm(form);
    biro.executeForm(form2);
  } catch (std::exception & e) {
    std::cout << e.what() << std::endl;
  }
  return 0;
}

