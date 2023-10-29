/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 11:35:39 by mamazzal          #+#    #+#             */
/*   Updated: 2023/10/29 16:53:49 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int main() {
  try {
    Bureaucrat biro("MBABO", 2);
    // AForm form("Form", 3, 3);
    // form.beSigned(biro);
    // biro.signForm(form);
    biro.incrementGrade();
    std::cout << biro << std::endl;
    
  } catch (std::exception & e) {
    std::cout << e.what() << std::endl;
  }
  return 0;
}

