/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   PmergeMe.hpp                         :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/12/03 12:09:12      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/12/05 12:03:37     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <cstdlib>
#include <deque>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <sys/time.h>
#include <vector>

#include "PmergeMe.hpp"

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
	struct timeval	 start_time;
	struct timeval	 end_time;
	long			 duration;
	std::vector<int> vicky;
	std::deque<int>	 duke;
} t_init;

// main.cpp
int			get_nbr_length(int nbr);
void		get_duration(t_init &s_i);
int			initializer(int argc, char **argv, t_init &s_i);

// PmergeMe.cpp
void		merge_intertion_vec(t_init &s_i);
int			sort_pairs_vec(t_init &s_i, int pair_size);
std::string print_vec(t_init &s_i);
#endif
