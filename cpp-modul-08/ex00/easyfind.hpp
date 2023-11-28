/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 21:25:21 by mamazzal          #+#    #+#             */
/*   Updated: 2023/11/28 10:16:40 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include "main.h"

template <typename T>
int easyfind(T & t, int __unused target) {
  std::vector<int>::iterator it  = t.begin();
  while (it != t.end()) {
    if (*it == target)
      return *it;
    it++;
  }
  throw std::string("Not found");
}

#endif