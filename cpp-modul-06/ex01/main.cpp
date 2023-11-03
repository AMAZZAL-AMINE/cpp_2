/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:07:18 by mamazzal          #+#    #+#             */
/*   Updated: 2023/11/03 12:33:39 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int main(void) {
  Data *data = new Data;
  data->somthingAreInt = 99;
  data->somthingAreStr = "nadfak";
  Serializer serializer;
  uintptr_t uintptr_ = serializer.serialize(data);
  std::cout << "uintptr_ => " << uintptr_ << " | " << "data => " << data << std::endl;
  data = serializer.deserialize(uintptr_);
  std::cout << data->somthingAreInt << std::endl;
  std::cout << data->somthingAreStr << std::endl;
  return 0;
}
