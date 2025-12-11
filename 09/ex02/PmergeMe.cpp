/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   PmergeMe.cpp                         :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/12/03 12:09:12      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/12/11 10:16:42     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include "PmergeMe.hpp"

std::vector<int> merge_intertion_vec(t_vec &s_i)
{
	// TODO
	// recreate a new t_vec fot this iteration with new:
	// 		maximum_value;
	// 		array_size;
	// 		nbr_length;
	dprint("Before sorting: ");
	dprint(print_vec(s_i));
	dprint("");

	sort_pairs_vec(s_i);

	dprint("Inserting the element paired with the smallest number");
	s_i.vicky.insert(s_i.vicky.begin(), s_i.vicky_pend[0]);
	s_i.vicky_pend.erase(s_i.vicky_pend.begin());
	dprint(print_vec(s_i));
	dprint("");

	dprint("Inserting the remaining elements");
	s_i.vicky_sort = s_i.vicky;

	std::vector<unsigned int> jacob = get_jacob_vec();

	dprint("After sorting: ");
	dprint(print_vec(s_i));

	return (s_i.vicky_sort);
}

std::vector<unsigned int> get_jacob_vec()
{
	std::vector<unsigned int> jacob;
	// jacob.push_back(0);
	// jacob.push_back(1);

	// unsigned int i = 2;
	// unsigned int prev1;
	// unsigned int prev2;
	// unsigned int current;
	// for (;;)
	// {
	// 	prev1 = jacob[i - 1];
	// 	prev2 = jacob[i - 2];
	// 	if (prev1 > INT_MAX - 2 * prev2)
	// 	{
	// 		break;
	// 	}

	// 	current = prev1 + 2 * prev2;
	// 	jacob.push_back(current);

	// 	i++;
	// }

	static const unsigned int array[]
		= {0,		  1,		 1,			3,		  5,		11,
		   21,		  43,		 85,		171,	  341,		683,
		   1365,	  2731,		 5461,		10923,	  21845,	43691,
		   87381,	  174763,	 349525,	699051,	  1398101,	2796203,
		   5592405,	  11184811,	 22369621,	44739243, 89478485, 178956971,
		   357913941, 715827883, 1431655765};

	// This is c++98
	jacob = std::vector<unsigned int>(array,
									  array + sizeof(array) / sizeof(array[0]));
	return (jacob);
}

void sort_pairs_vec(t_vec &s_i)
{
	dprint("Sorting the pairs");
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
	//// temporaty bubble sort /////////////////////////////////////////////////
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
	//// remove before deliverance /////////////////////////////////////////////
	dprint(print_vec(s_i));
	dprint("");
}

std::string print_vec(t_vec &s_i)
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
