/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:10:21 by mamazzal          #+#    #+#             */
/*   Updated: 2023/11/16 17:48:27 by mamazzal         ###   ########.fr       */
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
	if (str == "nan" || str == "+inf" || str == "-inf")
		throw (std::string)"impossible";
	if (str.length() == 1 && isPrint(str))
		char_  = str[0];
	else
		 char_ = StringToInt(str);
	bool isAscii = isPrint(str);
	if (isAscii) {
		_char = char_;
		return _char;
	}
	else if ((ascii(str) < 32 || ascii(str) > 127) && !isError())
		throw (std::string)"Non displayable";
	else
		throw (std::string)"impossible";
}


int ScalarConverter::toInt() {
	if (str == "nan" || str == "+inf" || str == "-inf")
		throw (std::string)"impossible";
	if (str.length() > 1 &&  isError())  {
		const std::string err = "impossible";
		throw err;
	}
	long res = 0;
	int count = 0;
	if (str.length() == 1 && !std::isdigit(str[0])) {
		_int = str[0];
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
			std::string err = "imposisble";
			throw err;
		}
    count++;
  }
	_int = res * minisFound;
	return _int;
}

float  ScalarConverter::toFloat() {
	if (str.length() > 1 &&  isError())  {
		const std::string err = "impossible";
		throw err;
	}
	if (str.length() == 1 && !std::isdigit(str[0])) {
		_float = static_cast<float>(str[0]);
		return _float;
 }
	_float = std::strtod(str.c_str(), NULL);
	return _float;
}

double  ScalarConverter::toDouble() {
	if (str.length() > 1 &&  isError())  {
		const std::string err = "impossible";
		throw err;
	}
	if (str.length() == 1 && !std::isdigit(str[0])) {
		_double =  static_cast<double>(str[0]);
		return _double;
 }
	_double = std::strtod(str.c_str(), NULL);
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
	int nbrSetprecision = getNbrSetprecision();

	try {	
		std::cout << "char: " << toChar()  << std::endl;
	} catch(const std::string & e) {
		std::cerr << e << '\n';
	}

	try {	
		std::cout << "int: " << toInt() << std::endl;
	} catch(const std::string & a) {
		std::cerr << a << '\n';
	}

	std::cout << std::fixed;
	try {	
		std::cout << std::setprecision(nbrSetprecision) << "float: "    << toFloat() << "f" << std::endl;
	} catch(const std::string & a) {
		std::cerr << a << '\n';
	}

	try {	
		std::cout << std::setprecision(nbrSetprecision) << "double: "   << toDouble() << std::endl;
	} catch(const std::string & a) {
		std::cerr << a << '\n';
	}
}
