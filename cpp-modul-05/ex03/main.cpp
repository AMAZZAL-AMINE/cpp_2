/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 11:35:39 by mamazzal          #+#    #+#             */
/*   Updated: 2023/10/30 13:54:19 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int main() {
  try {
    Bureaucrat bito("lferda", 30);
    Intern someRandomIntern;
    AForm* rrf;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    rrf->beSigned(bito);
    rrf->execute(bito);
  } catch (std::exception & e) {
    std::cout << e.what() << std::endl;
  }
  return 0;
}

