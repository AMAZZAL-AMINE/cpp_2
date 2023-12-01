/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:10:21 by mamazzal          #+#    #+#             */
/*   Updated: 2023/12/01 15:43:03 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

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
