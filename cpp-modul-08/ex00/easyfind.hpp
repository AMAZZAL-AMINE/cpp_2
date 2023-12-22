/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 21:25:21 by mamazzal          #+#    #+#             */
/*   Updated: 2023/12/21 13:26:00 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include "main.h"

template <typename T>
int easyfind(T & t, int __unused target) {
  std::vector<int>::iterator result = std::find(t.begin(), t.end(), target);
  if (result != t.end())
      return *result;
  throw std::string("Not found");
}

#endif