/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:39:24 by mamazzal          #+#    #+#             */
/*   Updated: 2023/12/01 10:54:56 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONERTER_HPP
#define SCALARCONERTER_HPP

#include "main.h"

class ScalarConverter {
  private :
    static std::string str;
    static int _int;
    static float _float;
    static double _double;
    static char  _char;
    static int getNbrSetprecision();
    static char toChar();
    static int toInt();
    static float toFloat();
    static double toDouble();
    ScalarConverter();
    
  public :
    ~ScalarConverter();
    ScalarConverter(ScalarConverter const &src);
    ScalarConverter &operator=(ScalarConverter const &rhs);

    static void    convert(std::string str);
    static int     isError();
    ScalarConverter(std::string str); 
};

#endif