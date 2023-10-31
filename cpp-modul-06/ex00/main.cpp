/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:07:18 by mamazzal          #+#    #+#             */
/*   Updated: 2023/10/31 20:38:49 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int main(int  __unused arc, char **argv) {
  if (arc != 2) {
    std::cout << "wrong number of argments " << std::endl;
    return 1;
  }
  ScalarConverter sc(argv[1]);
  sc.display();
  return 0;
}