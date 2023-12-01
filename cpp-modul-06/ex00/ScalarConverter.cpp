/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:10:21 by mamazzal          #+#    #+#             */
/*   Updated: 2023/12/01 12:06:49 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

// std::string ScalarConverter::str;
// int ScalarConverter::_int;
// char ScalarConverter::_char;
// float ScalarConverter::_float;
// double ScalarConverter::_double;

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(std::string str) {
	this->convert(str);
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const &src) {
	*this = src;
}

ScalarConverter & ScalarConverter::operator=(ScalarConverter const &rhs) {
	if (this != &rhs) {}
	return *this;
}


void ScalarConverter::convert(std::string s) {
	toChar(s);
	toInt(s);
	toFloat(s);
	toDouble(s);
}
