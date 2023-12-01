/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:06:49 by mamazzal          #+#    #+#             */
/*   Updated: 2023/12/01 12:03:35 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <iomanip> 
#include "ScalarConverter.hpp"

int StringToInt(std::string str);
int getNbrSetprecision(std::string & str);
double  toDouble(std::string & str);
float  toFloat(std::string & str);
int toInt(std::string & str);
char toChar(std::string & str);
int isError(std::string & str);
int ascii(std::string str);
int isPrint(std::string str);

#endif