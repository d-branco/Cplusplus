/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   PmergeMe.cpp                         :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/12/03 12:09:12      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/12/05 12:07:38     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void merge_intertion_vec(t_init &s_i)
{
	sort_pairs_vec(s_i, 1);
}

int sort_pairs_vec(t_init &s_i, int pair_size)
{
	(void) s_i;
	(void) pair_size;

	// recursion end

	// recursion a priore

	// recall

	// recursion a posteriori

	dprint(print_vec(s_i));
	return (0);
}

std::string print_vec(t_init &s_i)
{
	std::string ret = "Vec: ";
	for (unsigned int i = 1; i < s_i.vicky.size(); ++i)
	{
		if ((80 - 15 - 6) < (i * (s_i.nbr_length + 1)))
		{
			ret += " [...]";
			break;
		}
		std::ostringstream oss;
		oss << " " << std::setw(s_i.nbr_length) << s_i.vicky[i];
		ret += oss.str();
	}

	return (ret);
}