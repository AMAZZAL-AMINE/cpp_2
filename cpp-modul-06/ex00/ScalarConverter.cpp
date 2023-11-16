/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:10:21 by mamazzal          #+#    #+#             */
/*   Updated: 2023/11/16 16:48:03 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

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
	
	if (this->str == "nan" || this->str == "+inf" || this->str == "-inf")
		return 0;
	while (this->str[count] != '\0') {
		if (this->str[count] == '.')
			numberPoints++;
		else if (this->str[count] == 'f')
			numberF++;
		else if (this->str[count] == '-') {
			minisFound++;
			if (minisFound > 1 || count != 0)
				return 1;
		}
		else if (std::isalpha(this->str[count]))
			foundChar++;
		count++;
	}
	if (this->str.length() > 1 && (numberPoints > 1 || numberF > 1 || foundChar || minisFound > 1) )
		return 1;
	return 0;
}

char ScalarConverter::toChar() {
	int char_ ;
	if (this->str == "nan" || this->str == "+inf" || this->str == "-inf")
		throw (std::string)"impossible";
	if (this->str.length() == 1 && isPrint(this->str))
		char_  = this->str[0];
	else
		 char_ = StringToInt(this->str);
	bool isAscii = isPrint(this->str);
	if (isAscii) {
		this->_char = char_;
		return this->_char;
	}
	else if ((ascii(this->str) < 32 || ascii(this->str) > 127) && !isError())
		throw (std::string)"Non displayable";
	else
		throw (std::string)"impossible";
}


int ScalarConverter::toInt() {
	if (this->str == "nan" || this->str == "+inf" || this->str == "-inf")
		throw (std::string)"impossible";
	if (this->str.length() > 1 &&  isError())  {
		const std::string err = "impossible";
		throw err;
	}
	long res = 0;
	int count = 0;
	if (this->str.length() == 1 && !std::isdigit(this->str[0])) {
		this->_int = this->str[0];
		return this->_int;
 	}
	int minisFound = 1;
	if (this->str[0] == '-') {
		minisFound = -1;
		count++;
	}
	while (this->str[count] != '\0' && std::isdigit(this->str[count])) {
    res = res * 10 + str[count] - '0';
		if (res > INT_MAX) {
			std::string err = "imposisble";
			throw err;
		}
    count++;
  }
	this->_int = res * minisFound;
	return this->_int;
}

float  ScalarConverter::toFloat() {
	if (this->str.length() > 1 &&  isError())  {
		const std::string err = "impossible";
		throw err;
	}
	if (this->str.length() == 1 && !std::isdigit(this->str[0])) {
		this->_float = static_cast<float>(this->str[0]);
		return this->_float;
 }
	this->_float = std::strtod(this->str.c_str(), NULL);
	return this->_float;
}

double  ScalarConverter::toDouble() {
	if (this->str.length() > 1 &&  isError())  {
		const std::string err = "impossible";
		throw err;
	}
	if (this->str.length() == 1 && !std::isdigit(this->str[0])) {
		this->_double =  static_cast<double>(this->str[0]);
		return this->_double;
 }
	this->_double = std::strtod(this->str.c_str(), NULL);
	return this->_double;
}

int ScalarConverter::getNbrSetprecision() {
	int count = this->str.find('.');
	if (count <=  0)
		return 1;
	int counter_ = 0;
	int save = count;
	count++;
	while (this->str[count] != '\0') {
		if (std::isdigit(this->str[count]) && this->str[count] != '0')
			counter_ = count;
		count++;
	}
	counter_ = counter_ - save;
	if (counter_ <= 1)
		return 1;
	return counter_;
}


void ScalarConverter::convert(std::string str) {
	this->str = str;
	int nbrSetprecision = this->getNbrSetprecision();

	try {	
		std::cout << "char: " << this->toChar()  << std::endl;
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
