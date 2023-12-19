/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:39:35 by mamazzal          #+#    #+#             */
/*   Updated: 2023/12/19 14:33:19 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
int main(int argc, char **argv) {
  try {
    if (argc <  2) {
      std::cout << "Error : input not accepted\n";
      return 1;
    }
    int count = 1;
    PmergeMe fja;
    while (argv[count]) {
      fja.setNumbers(argv[count]);
      count++;
    }
    fja.merge();
    std::cout << "\n";
    std::cout << "vector conparizon : " << comparizonCound << std::endl;
    std::cout << "deque conparizon : " << comparizonCoundDeque << std::endl;
  } catch(std::exception & e) {
    std::cout << e.what() << std::endl;
  }
  return 0;
}


