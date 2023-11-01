/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:10:21 by mamazzal          #+#    #+#             */
/*   Updated: 2023/11/01 19:23:06 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

ScalarConverter::ScalarConverter(std::string str) {
	this->convert(str);
}

int ScalarConverter::isChar(std::string str) {
	unsigned long i = 0;
	while (i < str.length()) {
			if ((str[i] >= 'a' &&  str[i] <= 'z') || (str[i] >= 'A' &&  str[i] <= 'Z'))
				i++;
			else 
				return 0;
	}
	return 1;
}

int StringToInt(std::string str) {
  int count = 0;
  int res = 0;
  while (str[count] != '\0') {
    res = res * 10 + str[count] - '0';
    count++;
  }
  return res;
}

char ScalarConverter::toChar() {
	int char_ = StringToInt(this->str);
	bool isAscii = (char_ >= 65 && char_ <= 90) || (char_ >= 97 && char_ <= 122);
	if ((this->str.length() == 1 && std::isalpha(this->str[0])) || isAscii) {
		if (isAscii)
			this->_char = (char)char_;
		else 
			this->_char = this->str[0];
		return this->_char;
	}
	else if (this->str.length() > 1)
		throw (std::string)"impossible";
	else
		throw (std::string)"Non displayable";
}

int ScalarConverter::toInt() {
	if (str.length() > 1 && isChar(this->str))  {
		const std::string err = "impossible";
		throw err;
	}
	int res = 0;
	int count = 0;
  while (this->str[count] != '\0' && std::isdigit(this->str[count])) {
    res = res * 10 + str[count] - '0';
    count++;
  }
	this->_int = res;
	return this->_int;
}

float  ScalarConverter::toFloat() {
	this->_float = std::strtod(this->str.c_str(), NULL);
	return this->_float;
}

double  ScalarConverter::toDouble() {
	this->_double = std::strtod(this->str.c_str(), NULL);
	return this->_double;
}

int ScalarConverter::getNbrSetprecision() {
	int count = this->str.find('.');
	if (count == 0)
		return 1;
	int counter_ = 0;
	while (this->str[count] != '\0' && this->str[count] != '0') {
		counter_++;
		count++;
	}
	if (counter_ == 1)
		return 1;
	return counter_ - 1;
}

void ScalarConverter::convert(std::string str) {
	this->str = str;
	int nbrSetprecision = this->getNbrSetprecision();
	
	try {	
		std::cout << "char: " << this->toChar() << std::endl;
	} catch(const std::string & e) {
		std::cerr << e << '\n';
	}

	try {	
		std::cout << "int: " << this->toInt() << std::endl;
	} catch(const std::string & a) {
		std::cerr << a << '\n';
	}
	std::cout << std::fixed;
	std::cout << std::setprecision(nbrSetprecision) << "float: "    << this->toFloat() << "f" << std::endl;
	std::cout << std::setprecision(nbrSetprecision) << "double: "   << this->toDouble() << std::endl;
}
