/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:39:35 by mamazzal          #+#    #+#             */
/*   Updated: 2023/11/27 12:57:27 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int main(int argc, char __unused **argv) {
  if (argc != 2) {
    std::cerr << "Error: could not open file." << std::endl;
    return 1;
  }
  try {
    std::string file = argv[1];
    BitcoineExchange intputPars(file);
    intputPars.parse(0);
    BitcoineExchange dataParse("data.csv");
    dataParse.parse(1);
    // dataParse.display();
    intputPars.getPriceOfDay(dataParse);
  }catch(std::string & e) {
    std::cout << e << std::endl;
  }
  return 0;
}
