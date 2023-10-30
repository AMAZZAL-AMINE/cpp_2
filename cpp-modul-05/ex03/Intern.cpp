/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:31:18 by mamazzal          #+#    #+#             */
/*   Updated: 2023/10/30 11:35:01 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

Intern::Intern() {}

Intern::Intern(Intern const & src) {
  *this = src;
}

void Intern::operator=(Intern const & rhs) {
  (void)rhs;
}

Intern::~Intern() {}

/** _______________________ CLASS CONTENT ________________________  */

AForm Intern::makeForm(std::string formName, std::string target) {
  
}
