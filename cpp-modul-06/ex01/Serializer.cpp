/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 10:41:03 by mamazzal          #+#    #+#             */
/*   Updated: 2023/11/03 10:49:40 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

Serializer();
Serializer(Serializer const &src);
~Serializer();
Serializer &operator=(Serializer const &rhs);

Serializer::Serializer() {}

Serializer::Serializer(Serializer const &src) {
  *this = src;
}

Serializer::~Serializer() {}

Serializer &Serializer::operator=(Serializer const &rhs) {
  if (this != &rhs) {
    *this = rhs;
  }
  return *this;
}

uintptr_t Serializer::serialize(Data* ptr) {
  
}

Data * Serializer::deserialize(uintptr_t raw) {
  
}