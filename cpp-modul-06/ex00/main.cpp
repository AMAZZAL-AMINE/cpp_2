/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:07:18 by mamazzal          #+#    #+#             */
/*   Updated: 2023/11/16 17:35:37 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int main(int  __unused arc, char **argv) {
  if (arc != 2) {
    std::cout << "wrong number of argments " << std::endl;
    return 1;
  }
  ScalarConverter::convert(argv[1]);
  return 0;
}
