/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:10:21 by mamazzal          #+#    #+#             */
/*   Updated: 2023/11/02 15:17:03 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

ScalarConverter::ScalarConverter(std::string str) {
	this->convert(str);
}

int ScalarConverter::isChar(std::string str) {
	unsigned long i = 0;
	int found = 0;
	if (str == "nan"  ||  str == "+inf"  || str == "-inf")
		return 0;
	while (i < str.length()) {
			if ((str[i] >= 'a' &&  str[i] <= 'z') || (str[i] >= 'A' &&  str[i] <= 'Z')) {
					found += 1;
					break;
			}
			i++;
	}
	if (found  && str.length() > 1 && str[i] != 'f')
		return 1;
	else if (found == 1 && str[i] == 'f')
		return 0;
	return 0;
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
int isPrint(std::string str) {
	int nbr  = StringToInt(str);
	if (nbr >= 32 && nbr <= 126)
		return 1;
	return 0;
}

int convertToASCII(std::string letter) {
	int i = 0;
	int result = 0;
	if (letter.length() == 1 && isPrint(letter))
		return (int)letter[0];
	while (letter[i] != '\0') {
		result = result * 10 + letter[i] - '0';
		i++;
	}
	return result;
}

char ScalarConverter::toChar() {
	int char_  = convertToASCII(this->str);
	bool isAscii = isPrint(str);
	if (isAscii) {
		this->_char = char_;
		return this->_char;
	}
	else if (this->str.length() > 1)
		throw (std::string)"impossible";
	else
		throw (std::string)"Non displayable";
}

int ScalarConverter::toInt() {
	if ((str.length() > 1 && isChar(this->str)) || (str == "+inf"  || str == "-inf" || str == "nan"))  {
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
	if (this->str.length() > 1 && isChar(this->str))  {
		const std::string err = "impossible";
		throw err;
	}
	this->_float = std::strtod(this->str.c_str(), NULL);
	return this->_float;
}

double  ScalarConverter::toDouble() {
	if (str.length() > 1 && isChar(this->str))  {
		const std::string err = "impossible";
		throw err;
	}
	this->_double = std::strtod(this->str.c_str(), NULL);
	return this->_double;
}

int ScalarConverter::getNbrSetprecision() { //error here choolddd solve a brother
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
	try {	
		std::cout << std::setprecision(nbrSetprecision) << "float: "    << this->toFloat() << "f" << std::endl;
	} catch(const std::string & a) {
		std::cerr << a << '\n';
	}

	try {	
		std::cout << std::setprecision(nbrSetprecision) << "double: "   << this->toDouble() << std::endl;
	} catch(const std::string & a) {
		std::cerr << a << '\n';
	}
}
