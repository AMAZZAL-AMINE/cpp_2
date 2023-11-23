/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:39:35 by mamazzal          #+#    #+#             */
/*   Updated: 2023/11/23 17:01:56 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int main() {
  std::vector<int> vec;
  for(int i =0; i < 10; i++)
    vec.push_back(i);
  vec.push_back(100);
  try {
    std::cout << easyfind(vec, 5) << std::endl;
    std::cout << easyfind(vec, 100) << std::endl;
    std::cout << easyfind(vec, 101) << std::endl;
  }catch(std::string e) {
    std::cout << e << std::endl;
  }
  return 0;
}
