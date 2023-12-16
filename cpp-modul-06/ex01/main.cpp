/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:07:18 by mamazzal          #+#    #+#             */
/*   Updated: 2023/12/16 09:27:23 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int main(void) {
  Data *data = new Data;
  data->somthingAreInt = 99;
  data->somthingAreStr = "nadfak";

  uintptr_t uintptr_ = Serializer::serialize(data);
  std::cout << "uintptr_ => " << uintptr_ << " | " << "data => " << data << std::endl;
  data = Serializer::deserialize(uintptr_);
  std::cout << data->somthingAreInt << std::endl;
  std::cout << data->somthingAreStr << std::endl;
  delete data;
  return 0;
}
