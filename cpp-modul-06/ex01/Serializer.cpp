/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 10:41:03 by mamazzal          #+#    #+#             */
/*   Updated: 2023/12/01 17:52:58 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

Serializer::Serializer() {}

Serializer::Serializer(Serializer const &src) {
  *this = src;
}

Serializer::~Serializer() {}

Serializer &Serializer::operator=(Serializer const &rhs) {
    if (this != &rhs) {}
  return *this;
}

uintptr_t Serializer::serialize(Data* ptr) {
  return reinterpret_cast<uintptr_t>(ptr);
}

Data * Serializer::deserialize(uintptr_t raw) {
  return reinterpret_cast<Data *>(raw);
}
