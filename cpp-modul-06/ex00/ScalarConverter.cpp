/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:10:21 by mamazzal          #+#    #+#             */
/*   Updated: 2023/10/31 20:36:24 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

ScalarConverter::ScalarConverter(std::string str) {
	this->convert(str);
}

void ScalarConverter::convert(std::string str) {
	std::cout << "convert" << std::endl;
	this->str = str;
	this->_int = std::atoi(this->str.c_str());
	this->_float =  std::stod(this->str);
	this->_double = std::atof(this->str.c_str());
	this->_char = str[0];
}

void ScalarConverter::display() const {
	std::cout << "char: " << this->_char << std::endl;
	std::cout << "int: " << this->_int << std::endl;
	std::cout << std::fixed;
	std::cout << std::setprecision(1) << "float: "    << this->_float << std::endl;
	std::cout << std::setprecision(1) << "double: "   << this->_double << std::endl;
}
