/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   PmergeMe.hpp                         :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/12/03 12:09:12      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/12/12 15:41:45     #########  #########  ###      ###      */
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

typedef std::pair<int, int> t_pair_o_int;

class PmergeMeVec
{
  public:
	PmergeMeVec();
	PmergeMeVec(const PmergeMeVec &src);
	~PmergeMeVec();
	PmergeMeVec		 &operator=(const PmergeMeVec &rhs);

	std::vector<int>  run();
	void			  push_back(int val);
	std::vector<int> &getVec();
	size_t			  getSize() const;
	int				  getNbrLength() const;
	int				  getMax() const;
	void			  setMax(int val);
	void			  setNbrLength(int val);

  private:
	int								 maximum_value_;
	int								 array_size_;
	int								 nbr_length_;
	std::vector<int>				 vec_;
	std::vector<int>				 pend_;
	std::vector<int>				 sort_;

	void							 sortPairs();
	void							 insert();
	std::string						 print();

	static std::vector<unsigned int> getJacobVec();
	static int						 calcNbrLength(int nbr);
};

class PmergeMeDeq
{
  public:
	PmergeMeDeq();
	PmergeMeDeq(const PmergeMeDeq &src);
	~PmergeMeDeq();
	PmergeMeDeq		&operator=(const PmergeMeDeq &rhs);

	std::deque<int>	 run();
	void			 push_back(int val);
	std::deque<int> &getDeq();
	size_t			 getSize() const;
	int				 getNbrLength() const;
	int				 getMax() const;
	void			 setMax(int val);
	void			 setNbrLength(int val);

  private:
	int								 maximum_value_;
	int								 array_size_;
	int								 nbr_length_;
	std::deque<int>					 deq_;
	std::deque<int>					 pend_;
	std::deque<int>					 sort_;

	void							 sortPairs();
	void							 insert();
	std::string						 print();

	static std::vector<unsigned int> getJacobVec();
	static int						 calcNbrLength(int nbr);
};

// main.cpp
int get_nbr_length(int nbr);
int initializer(int argc, char **argv, PmergeMeVec &s_v, PmergeMeDeq &s_d);

#endif
