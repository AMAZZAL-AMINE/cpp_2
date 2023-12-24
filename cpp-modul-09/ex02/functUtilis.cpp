/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functUtilisVector.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:06:58 by mamazzal          #+#    #+#             */
/*   Updated: 2023/12/24 23:46:08 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int comparizonCound = 0;

int compare(const std::vector<int> & a, const  std::vector<int> & b) {
  comparizonCound++;
  return (a.back() < b.back());
}

std::vector<int> jacobsthalGenerator(int max) {
  std::vector<int> J;
  int count = 2;
  int result = 0;
  J.push_back(0);
  J.push_back(1);
  while (result <= max) {
    int re = J[count - 1] + (2 * J[count - 2]);
    J.push_back(re);
    result = re;
    count++;
  }
  J.erase(J.begin());
  J.erase(J.begin());
  return J;
}

int comparizonCoundDeque = 0;

int compareDeque(const std::deque<int> & a,const std::deque<int> & b) {
  comparizonCoundDeque++;
  return (a.back() < b.back());
}

std::deque<int> jacobsthalGeneratorDeque(int max) {
  std::deque<int> J;
  int count = 2;
  int result = 0;
  J.push_back(0);
  J.push_back(1);
  while (result <= max) {
    int re = J[count - 1] + (2 * J[count - 2]);
    J.push_back(re);
    result = re;
    count++;
  }
  J.erase(J.begin());
  J.erase(J.begin());
  return J;
}
