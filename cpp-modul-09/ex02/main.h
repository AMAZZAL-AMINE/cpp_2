/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:39:38 by mamazzal          #+#    #+#             */
/*   Updated: 2023/12/19 14:33:07 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <vector>
#include <deque>
#include "PmergeMe.hpp"

extern int comparizonCound;
extern int comparizonCoundDeque;
long satoi(std::string nbr);
int compare(const std::vector<int> & a, const  std::vector<int> & b);
std::vector<int> jacobsthalGenerator(int max);
std::vector<int>  pairsToVector(std::vector<std::pair<std::vector<int>, std::vector<int> > > & pairs, size_t size);
std::vector<std::pair<std::vector<int>, std::vector<int> > > createPairs(std::vector<int> & vec, int size);

std::deque<int>  pairsToDeque(std::deque<std::pair<std::deque<int>, std::deque<int> > > & pairs, size_t size);
std::deque<int> jacobsthalGeneratorDeque(int max);
std::deque<std::pair<std::deque<int>, std::deque<int> > > createPairsDeque(std::deque<int> & vec, int size);
int compareDeque(const std::deque<int> & a,const std::deque<int> & b);

#endif