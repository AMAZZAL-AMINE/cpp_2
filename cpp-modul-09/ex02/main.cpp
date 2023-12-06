/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:39:35 by mamazzal          #+#    #+#             */
/*   Updated: 2023/12/04 19:45:20 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
int main(int argc, char __unused **argv) {
  if (argc < 2) {
    std::cout << "Error : invalid argments." << std::endl;
    return 1;
  }
  try {
    PmergeMe  PmergeObj;
    int i = 0;
    std::string arg;
    while (argv[++i]) {
      arg = argv[i];
      PmergeObj.checkArgment(arg);
      PmergeObj.pushArg(arg);
    }
    PmergeObj.start();
    PmergeObj.displayStackBefor();
  }catch(std::string & e) {
    std::cout << e << std::endl;
  }
  return 0;
}

