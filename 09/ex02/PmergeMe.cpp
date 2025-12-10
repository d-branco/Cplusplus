/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   PmergeMe.cpp                         :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/12/03 12:09:12      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/12/10 22:26:08     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void merge_intertion_vec(t_init &s_i)
{
	dprint("Before sorting: ");
	dprint(print_vec(s_i));
	dprint("");

	sort_pairs_vec(s_i);

	dprint("After sorting: ");
	dprint(print_vec(s_i));
}

void sort_pairs_vec(t_init &s_i)
{
	for (size_t i = 0; i + 2 <= s_i.vicky.size(); i++)
	{
		if (s_i.vicky[i] > s_i.vicky[i + 1])
		{
			s_i.vicky_pend.push_back(s_i.vicky[i + 1]);
			s_i.vicky.erase(s_i.vicky.begin() + i + 1);
		}
		else
		{
			s_i.vicky_pend.push_back(s_i.vicky[i]);
			s_i.vicky.erase(s_i.vicky.begin() + i);
		}
	}
	size_t tmp_size = s_i.vicky_pend.size();
	while (s_i.vicky.size() > tmp_size)
	{
		s_i.vicky_pend.push_back(s_i.vicky[(s_i.vicky.size() - 1)]);
		s_i.vicky.erase(s_i.vicky.end());
	}
	dprint(print_vec(s_i));
	dprint("");

	dprint("|| TODO || Recursively call itsel to order half of itself!");
	//// temporaty bubble sort
	size_t i	= 0;
	int	   temp = 0;
	while (i < s_i.vicky.size() - 1)
	{
		if (s_i.vicky[i + 1] < s_i.vicky[i])
		{
			temp			 = s_i.vicky[i + 1];
			s_i.vicky[i + 1] = s_i.vicky[i];
			s_i.vicky[i]	 = temp;

			temp				  = s_i.vicky_pend[i + 1];
			s_i.vicky_pend[i + 1] = s_i.vicky_pend[i];
			s_i.vicky_pend[i]	  = temp;

			i = 0;
			continue;
		}
		i++;
	}
	//// remove before deliverance
	dprint(print_vec(s_i));
	dprint("");

	return;
}

std::string print_vec(t_init &s_i)
{
	std::string ret = "Vec:  ";
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
	ret += "\n==DEBUG== pend: ";
	for (unsigned int i = 0; i < s_i.vicky_pend.size(); ++i)
	{
		if ((80 - 15 - 6) < (i * (s_i.nbr_length + 1)))
		{
			ret += " [...]";
			break;
		}
		std::ostringstream oss;
		oss << " " << std::setw(s_i.nbr_length) << s_i.vicky_pend[i];
		ret += oss.str();
	}
	ret += "\n==DEBUG== sort: ";
	for (unsigned int i = 0; i < s_i.vicky_sort.size(); ++i)
	{
		if ((80 - 15 - 6) < (i * (s_i.nbr_length + 1)))
		{
			ret += " [...]";
			break;
		}
		std::ostringstream oss;
		oss << " " << std::setw(s_i.nbr_length) << s_i.vicky_sort[i];
		ret += oss.str();
	}
	return (ret);
}
