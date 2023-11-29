/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:39:35 by mamazzal          #+#    #+#             */
/*   Updated: 2023/11/29 22:49:53 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int main(int argc, char __unused **argv) {
  if (argc != 2) {
    std::cout << "WTF ? bro where is the  inverted Polish mathematical expression!!" << std::endl;
    return 1;
  }
  try {
    RPN rpnObj;
    rpnObj.setArgments(argv[1]);
    rpnObj.getResult();
  }catch(std::string & e) {
    std::cout << e << std::endl;
  }
  return 0;
}

