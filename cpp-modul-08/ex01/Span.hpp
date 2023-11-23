/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 21:25:17 by mamazzal          #+#    #+#             */
/*   Updated: 2023/11/23 21:25:18 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include "main.h"

class Span {
    private :
      unsigned int max;
      std::vector<int> integers;
    public :
      Span();
      Span(Span const &src);
      Span &operator=(Span const &src);
      ~Span();
      
      Span(unsigned int N);
      void addNumber(int N);
      int shortestSpan();
      int longestSpan();

  };

#endif