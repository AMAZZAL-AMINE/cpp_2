/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functUtilisDeque.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:06:58 by mamazzal          #+#    #+#             */
/*   Updated: 2023/12/19 14:21:19 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

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

std::deque<int>  pairsToDeque(std::deque<std::pair<std::deque<int>, std::deque<int> > > & pairs, size_t size) {
  std::deque<int> vec;
  for (size_t i = 0; i < pairs.size(); i++) {
    std::deque<int>& subdeque = pairs[i].first;
    std::deque<int>& ssubdeque = pairs[i].second;
    for (size_t j = 0; j < size; j++)
      vec.push_back(subdeque[j]);
    for (size_t j = 0; j < size; j++)
      vec.push_back(ssubdeque[j]);
  }
  return vec;
}

std::deque<std::pair<std::deque<int>, std::deque<int> > > createPairsDeque(std::deque<int> & vec, int size) {
  size_t count = 0;
  std::deque<std::pair<std::deque<int>, std::deque<int> > > pairs;
  while (count < vec.size()) {
    std::deque<int> first, secnd;
    size_t index = count;
    while(index < count + size) {
      first.push_back(vec[index]);
      index++;
    }
    index = count + size;
    while(index < count + (size * 2)) {
      secnd.push_back(vec[index]);
      index++;
    }
    comparizonCoundDeque++;
    if (first.back() > secnd.back())
      std::swap(first, secnd);
    pairs.push_back(std::make_pair(first, secnd));
    count += size * 2;
  }
  return pairs;
}
