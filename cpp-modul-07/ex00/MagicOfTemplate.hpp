/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MagicOfTemplate.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:39:31 by mamazzal          #+#    #+#             */
/*   Updated: 2023/11/22 12:46:04 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAGICOFTEMPLATE_HPP
#define MAGICOFTEMPLATE_HPP

#include "main.h"

template <typename T>
void swap(T & t1, T & t2) {
  T tmp = t1;
  t1 = t2;
  t2 = tmp;
}

template <typename T>
T min(T & t1, T & t2) {
  return (t1 > t2 || t1 == t2) ? t2 :  t1;
}

template <typename T> 
T max(T & t1, T & t2) {
  return (t1 > t2) ? t1 :  t2;
}

#endif