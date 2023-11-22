/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:39:35 by mamazzal          #+#    #+#             */
/*   Updated: 2023/11/22 19:48:43 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int main() {
  try {
    Array<std::string>  arr(6);
    arr[2] = "hello";
    std::cout << arr[2] << std::endl;
  }catch(std::exception & e) {
    std::cout << e.what() << std::endl;
  }
  return 0;
}
