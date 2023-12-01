/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:10:21 by mamazzal          #+#    #+#             */
/*   Updated: 2023/12/01 11:07:27 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

std::string ScalarConverter::str;
int ScalarConverter::_int;
char ScalarConverter::_char;
float ScalarConverter::_float;
double ScalarConverter::_double;

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(std::string str) {
	this->convert(str);
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const &src) {
	*this = src;
}

ScalarConverter & ScalarConverter::operator=(ScalarConverter const &rhs) {
	if (this != &rhs) {
		this->str = rhs.str;
		this->_int = rhs._int;
		this->_float = rhs._float;
		this->_double = rhs._double;
		this->_char = rhs._char;
	}
	return *this;
}


int isPrint(std::string str) {
	if (str.length() == 1 && std::isprint(str[0]) && !std::isdigit(str[0]))
		return 1;
	int nbr  = StringToInt(str);
	if (nbr >= 32 && nbr <= 126)
		return 1;
	return 0;
}


int ascii(std::string str) {
  int count = 0;
  int rsult = 0;
  while (str[count] != '\0' && std::isdigit(str[count])) {
    rsult = rsult * 10 + str[count]  - '0';
    count++;
  }
  return rsult;
}

int StringToInt(std::string str) {
  int count = 0;
  int res = 0;
	
  while (str[count] != '\0' && std::isdigit(str[count])) {
    res = res * 10 + str[count] - '0';
    count++;
  }
  return res;
}

int ScalarConverter::isError() {
	int count = 0;
	int numberPoints = 0;
	int numberF = 0;
	int foundChar = 0;
	int minisFound = 0;
	
	if (str == "nan" || str == "+inf" || str == "-inf")
		return 0;
	while (str[count] != '\0') {
		if (str[count] == '.')
			numberPoints++;
		else if (str[count] == 'f')
			numberF++;
		else if (str[count] == '-') {
			minisFound++;
			if (minisFound > 1 || count != 0)
				return 1;
		}
		else if (std::isalpha(str[count]))
			foundChar++;
		count++;
	}
	if (str.length() > 1 && (numberPoints > 1 || numberF > 1 || foundChar || minisFound > 1) )
		return 1;
	return 0;
}

char ScalarConverter::toChar() {
	int char_ ;
	if (str == "nan" || str == "+inf" || str == "-inf") {
		std::cout << "char: impossible" << std::endl;
		return -1;
	}
	if (str.length() == 1 && isPrint(str))
		char_  = str[0];
	else
		 char_ = StringToInt(str);
	bool isAscii = isPrint(str);
	if (isAscii) {
		_char = char_;
		std::cout << "char: " << _char  << std::endl;
		return _char;
	}
	else if ((ascii(str) < 32 || ascii(str) > 127) && !isError())
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: impossible" << std::endl;
	return -1;
}


int ScalarConverter::toInt() {
	if (str == "nan" || str == "+inf" || str == "-inf" || (str.length() > 1 &&  isError())) {
		std::cout << "int: impossible" << std::endl;
		return -1;
	}

	long res = 0;
	int count = 0;
	if (str.length() == 1 && !std::isdigit(str[0])) {
		_int = str[0];
		std::cout << "int: " << _int << std::endl;
		return _int;
 	}
	int minisFound = 1;
	if (str[0] == '-') {
		minisFound = -1;
		count++;
	}
	while (str[count] != '\0' && std::isdigit(str[count])) {
    res = res * 10 + str[count] - '0';
		if (res > INT_MAX) {
			std::cout << "int: impossible" << std::endl;
			return -1;
		}
    count++;
  }
	_int = res * minisFound;
	std::cout << "int: " << _int << std::endl;
	return _int;
}

float  ScalarConverter::toFloat() {
	if (str.length() > 1 &&  isError())  {
		std::cout <<  "float: impossible" << std::endl;
		return -1;
	}
	int nbrSetprecision = getNbrSetprecision();
	if (str.length() == 1 && !std::isdigit(str[0])) {
		_float = static_cast<float>(str[0]);
 }else {
	_float = std::strtod(str.c_str(), NULL);
 }
	std::cout << std::setprecision(nbrSetprecision) << "float: "    << _float << "f" << std::endl;
	return _float;
}

double  ScalarConverter::toDouble() {
	if (str.length() > 1 &&  isError())  {
		std::cout << "double: impossible" << std::endl;
		return -1;
	}
	int nbrSetprecision = getNbrSetprecision();
	if (str.length() == 1 && !std::isdigit(str[0])) {
		_double =  static_cast<double>(str[0]);
 	}else {
		_double = std::strtod(str.c_str(), NULL);
 	}
	std::cout << std::setprecision(nbrSetprecision) << "double: " <<_double << std::endl;
	return _double;
}

int ScalarConverter::getNbrSetprecision() {
	int count = str.find('.');
	if (count <=  0)
		return 1;
	int counter_ = 0;
	int save = count;
	count++;
	while (str[count] != '\0') {
		if (std::isdigit(str[count]) && str[count] != '0')
			counter_ = count;
		count++;
	}
	counter_ = counter_ - save;
	if (counter_ <= 1)
		return 1;
	return counter_;
}


void ScalarConverter::convert(std::string s) {
	str = s;

	toChar();
	toInt();
	std::cout << std::fixed;
	toFloat();
	toDouble();
}
