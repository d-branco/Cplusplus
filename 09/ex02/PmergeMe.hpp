/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   PmergeMe.hpp                         :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/12/03 12:09:12      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/12/10 13:38:00     #########  #########  ###      ###      */
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
	std::vector<int> vicky_pend;
	std::deque<int>	 duke;
	std::deque<int>	 duke_pend;
} t_init;

// main.cpp
int			get_nbr_length(int nbr);
void		get_duration(t_init &s_i);
int			initializer(int argc, char **argv, t_init &s_i);

// PmergeMe.cpp
void		merge_intertion_vec(t_init &s_i);
void		sort_pairs_vec(t_init &s_i, unsigned int pair_size);
std::string print_vec(t_init &s_i, unsigned int pair_size);
void		separate_chains_vec(t_init &s_i, unsigned int pair_size);
std::string print_pend_vec(t_init &s_i);

#endif
