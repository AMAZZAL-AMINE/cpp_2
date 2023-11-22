/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:39:35 by mamazzal          #+#    #+#             */
/*   Updated: 2023/11/22 12:51:51 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int main() {
  int a = 2;
  int b = 3;
  swap( a, b );
  std::cout << "a = " << a << ", b = " << b << std::endl;
  std::cout << "min( a, b ) = " << min( a, b ) << std::endl;
  std::cout << "max( a, b ) = " << max( a, b ) << std::endl;
  std::string c = "chaine1";
  std::string d = "chaine2";
  swap(c, d);
  std::cout << "c = " << c << ", d = " << d << std::endl;
  std::cout << "min( c, d ) = " << min( c, d ) << std::endl;
  std::cout << "max( c, d ) = " << max( c, d ) << std::endl;
  {  
    int a = 100;
    int b = 5;
    ::swap(a, b);
    std::cout << "A => " << a << "\n" << "B => " << b << std::endl;
  }
  return 0;
}
