/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   PmergeMe.hpp                         :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/12/03 12:09:12      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/12/11 08:39:09     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <cstdlib>
#include <deque>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <sys/time.h>
#include <vector>

#ifdef DEBUG
# define dprint(msg) std::cout << "==DEBUG== " << msg << "\n"
#else
# define dprint(msg) ((void) 0)
#endif

typedef struct s_init_vec
{
	int				 maximum_value;
	int				 array_size;
	int				 nbr_length;

	std::vector<int> vicky;
	std::vector<int> vicky_pend;
	std::vector<int> vicky_sort;
} t_vec;

// typedef struct s_init_vec
// {
// 	int				 maximum_value;
// 	int				 array_size;
// 	int				 nbr_length;

// 	// std::deque<in?
// } t_vec;

// main.cpp
int				 get_nbr_length(int nbr);
int				 initializer(int argc, char **argv, t_vec &s_i);

// PmergeMe.cpp
// std::vector<int> merge_intertion_vec(std::vector<int> vicky);
std::vector<int> merge_intertion_vec(t_vec &s_i);
void			 sort_pairs_vec(t_vec &s_i);
std::string		 print_vec(t_vec &s_i);

#endif