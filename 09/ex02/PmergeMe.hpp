/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   PmergeMe.hpp                         :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/12/03 12:09:12      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/12/11 18:45:40     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <cstdlib>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits.h>
#include <sstream>
#include <string>
#include <sys/time.h>
#include <utility>
#include <vector>

#ifdef DEBUG
# define dprint(msg) std::cout << "==DEBUG== " << msg << "\n"
#else
# define dprint(msg) ((void) 0)
#endif

typedef struct s_vec
{
	int				 maximum_value;
	int				 array_size;
	int				 nbr_length;
	std::vector<int> vicky;
	std::vector<int> vicky_pend;
	std::vector<int> vicky_sort;
} t_vec;

typedef struct s_deq
{
	int				maximum_value;
	int				array_size;
	int				nbr_length;

	std::deque<int> duke;
	std::deque<int> duke_pend;
	std::deque<int> duke_sort;
} t_deq;

typedef std::pair<int, int> t_pair_o_int;

// main.cpp
int							get_nbr_length(int nbr);
int				 initializer(int argc, char **argv, t_vec &s_v, t_deq &s_d);

// PmergeMe.cpp
std::vector<int> merge_intertion_vec(t_vec &s_v);
void			 sort_pairs_vec(t_vec &s_v);
std::string		 print_vec(t_vec &s_v);
void			 insert_vec(t_vec &s_v);

std::vector<unsigned int> get_jacob_vec();

std::deque<int>			  merge_intertion_deq(t_deq &s_d);
// void					  sort_pairs_deq(t_deq &s_d);
std::string				  print_deq(t_deq &s_d);
// void					  insert_deq(t_deq &s_d);
#endif