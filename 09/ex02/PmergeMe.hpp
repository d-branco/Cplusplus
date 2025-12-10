/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   PmergeMe.hpp                         :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/12/03 12:09:12      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/12/10 21:33:47     #########  #########  ###      ###      */
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

typedef struct s_init
{
	int				 maximum_value;
	int				 array_size;
	int				 nbr_length;

	std::vector<int> vicky;
	std::vector<int> vicky_pend;
	std::vector<int> vicky_sort;

	std::deque<int>	 duke;
	std::deque<int>	 duke_pend;
	std::deque<int>	 duke_sort;
} t_init;

// main.cpp
int			get_nbr_length(int nbr);
int			initializer(int argc, char **argv, t_init &s_i);

// PmergeMe.cpp
// std::vector<int> merge_intertion_vec(std::vector<int> vicky);
void		merge_intertion_vec(t_init &s_i);
void		sort_pairs_vec(t_init &s_i);
std::string print_vec(t_init &s_i);

#endif