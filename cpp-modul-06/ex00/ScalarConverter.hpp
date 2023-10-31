/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:39:24 by mamazzal          #+#    #+#             */
/*   Updated: 2023/10/31 17:46:15 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONERTER_HPP
#define SCALARCONERTER_HPP

#include "main.h"

class ScalarConverter {
  private :
    std::string str;
    int _int;
    float _float;
    double _double;
    char _char;
    ScalarConverter();
  public :
    void    convert(std::string str);
    void    display() const;
    ScalarConverter(std::string str); 
};

#endif