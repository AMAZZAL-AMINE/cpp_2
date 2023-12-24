/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:39:38 by mamazzal          #+#    #+#             */
/*   Updated: 2023/12/24 23:55:37 by mamazzal         ###   ########.fr       */
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
std::deque<int> jacobsthalGeneratorDeque(int max);
int compareDeque(const std::deque<int> & a,const std::deque<int> & b);

#endif