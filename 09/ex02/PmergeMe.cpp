/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   PmergeMe.cpp                         :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/12/03 12:09:12      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/12/05 18:53:25     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void merge_intertion_vec(t_init &s_i)
{
	dprint("Before pair sorting: ");
	dprint(print_vec(s_i, 0));
	dprint("");
	for (unsigned int i = 1; i <= s_i.vicky.size() / 2; i *= 2)
	{
		dprint("Sorting pairs of size: " << i);
		sort_pairs_vec(s_i, i);
		dprint("");
	}
	dprint("After pair sorting: ");
	dprint(print_vec(s_i, 0));
}

int sort_pairs_vec(t_init &s_i, unsigned int pair_size)
{
	(void) s_i;
	(void) pair_size;

	////
	for (unsigned int i = 0; i < (s_i.vicky.size() / pair_size);
		 i += pair_size * 2)
	{
		dprint("Swaping " << s_i.vicky[i + pair_size - 1] << " with ...");
	}
	////
	dprint(print_vec(s_i, pair_size));
	return (0);
}

std::string print_vec(t_init &s_i, unsigned int pair_size)
{
	std::string ret = "SWAP: ";

	if ((pair_size != 0)
		&& (((pair_size * s_i.nbr_length + (pair_size - 1)) + 1) <= 60))
	{
		pair_size *= 2;
		for (unsigned int i = 0; i < (s_i.vicky.size() / pair_size); ++i)
		{
			for (unsigned int j = 1;
				 j <= (pair_size * s_i.nbr_length + (pair_size - 1));
				 j++)
			{
				ret += "_";
			}
			ret += " ";
			if ((((pair_size * s_i.nbr_length + (pair_size - 1)) + 1) * (i + 1))
				> 60)
			{
				break;
			}
		}
		pair_size /= 2;
	}
	ret += "\n==DEBUG== Vec: ";
	for (unsigned int i = 0; i < s_i.vicky.size(); ++i)
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
	if (pair_size == 0)
	{
		return (ret);
	}
	ret += "\n==DEBUG== PAIR: ";
	if (((pair_size * s_i.nbr_length + (pair_size - 1)) + 1) > 60)
	{
		return (ret);
	}
	for (unsigned int i = 0; i < (s_i.vicky.size() / pair_size); ++i)
	{
		for (unsigned int j = 1;
			 j <= (pair_size * s_i.nbr_length + (pair_size - 1));
			 j++)
		{
			ret += "‾";
		}
		ret += " ";
		if ((((pair_size * s_i.nbr_length + (pair_size - 1)) + 1) * (i + 1))
			> 60)
		{
			break;
		}
	}
	return (ret);
}
