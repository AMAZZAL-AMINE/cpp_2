/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functUtilis.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:06:58 by mamazzal          #+#    #+#             */
/*   Updated: 2023/12/19 13:41:44 by mamazzal         ###   ########.fr       */
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

std::vector<int>  pairsToVector(std::vector<std::pair<std::vector<int>, std::vector<int> > > & pairs, size_t size) {
  std::vector<int> vec;
  for (size_t i = 0; i < pairs.size(); i++) {
    std::vector<int>& subvector = pairs[i].first;
    std::vector<int>& ssubvector = pairs[i].second;
    for (size_t j = 0; j < size; j++)
      vec.push_back(subvector[j]);
    for (size_t j = 0; j < size; j++)
      vec.push_back(ssubvector[j]);
  }
  return vec;
}

std::vector<std::pair<std::vector<int>, std::vector<int> > > createPairs(std::vector<int> & vec, int size) {
  size_t count = 0;
  std::vector<std::pair<std::vector<int>, std::vector<int> > > pairs;
  while (count < vec.size()) {
    std::vector<int> first, secnd;
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
    comparizonCound++;
    if (first.back() > secnd.back())
      std::swap(first, secnd);
    pairs.push_back(std::make_pair(first, secnd));
    count += size * 2;
  }
  return pairs;
}
