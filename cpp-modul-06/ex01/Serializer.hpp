/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 10:41:23 by mamazzal          #+#    #+#             */
/*   Updated: 2023/12/16 09:26:29 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include "main.h"

class Serializer {
  private :
    Serializer();
  public :
    Serializer(Serializer const &src);
    ~Serializer();
    Serializer &operator=(Serializer const &rhs);

    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};

#endif