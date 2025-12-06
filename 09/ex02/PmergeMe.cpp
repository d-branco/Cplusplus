/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   PmergeMe.cpp                         :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/12/03 12:09:12      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/12/06 21:37:35     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void merge_intertion_vec(t_init &s_i)
{
	dprint("Before sorting: ");
	dprint(print_vec(s_i, 0));
	dprint("");

	sort_pairs_vec(s_i, 1);

	dprint("After sorting: ");
	dprint(print_vec(s_i, 0));
}

int sort_pairs_vec(t_init &s_i, unsigned int pair_size)
{
	////
	dprint("sort_pairs_vec(" << pair_size << "): init");
	if (pair_size * 2 > s_i.vicky.size())
	{
		dprint("sort_pairs_vec("
			   << pair_size
			   << "): End of recursion -> pairing size two big for two pairs.");
		dprint("");
		return (0);
	}
	////

	dprint(print_vec(s_i, 0));
	for (size_t i = 0; i + 2 * pair_size <= s_i.vicky.size();
		 i += 2 * pair_size)
	{
		size_t i_a = i + pair_size - 1;
		size_t i_b = i + 2 * pair_size - 1;

		if (s_i.vicky[i_a] > s_i.vicky[i_b])
		{
			dprint("Swapping pair blocks...");
			std::swap_ranges(s_i.vicky.begin() + i,
							 s_i.vicky.begin() + i + pair_size,
							 s_i.vicky.begin() + i + pair_size);
			dprint(print_vec(s_i, pair_size));
		}
	}

	dprint("sort_pairs_vec(" << pair_size << "): recursive call for pair "
							 << (pair_size * 2));
	sort_pairs_vec(s_i, pair_size * 2);

	dprint("sort_pairs_vec(" << pair_size << "): insert the pend elements");

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
	ret += "\n==DEBUG== BLOC: ";
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
