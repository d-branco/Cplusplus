/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   PmergeMe.cpp                         :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/12/03 12:09:12      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/12/11 18:50:58     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/////////////////////////////////////////////////////////////////////// Deque //
std::deque<int> merge_intertion_deq(t_deq &s_i)
{
	t_deq s_d;
	s_d.duke		  = s_i.duke;
	s_d.maximum_value = -1;
	for (size_t i = 0; i < s_d.duke.size(); i++)
	{
		if (s_d.duke[i] > s_d.maximum_value)
		{
			s_d.maximum_value = s_d.duke[i];
		}
	}
	s_d.array_size = s_d.duke.size();
	s_d.nbr_length = get_nbr_length(s_d.maximum_value);

	dprint("Before sorting: ");
	dprint(print_deq(s_d));
	dprint("");

	// sort_pairs_dec(s_d);

	dprint("Inserting the element paired with the smallest number");
	// s_d.duke.insert(s_d.duke.begin(), s_d.duke_pend[0]);
	// s_d.duke_pend.erase(s_d.duke_pend.begin());
	dprint(print_deq(s_d));
	dprint("");

	dprint("Inserting the remaining elements");
	s_d.duke_sort = s_d.duke;

	dprint("Insertion init");
	dprint(print_deq(s_d));
	// insert_vec(s_d);
	dprint("Insertion finit");
	dprint("");

	dprint("After sorting: ");
	dprint(print_deq(s_d));
	dprint("");

	return (s_d.duke_sort);
}

std::string print_deq(t_deq &s_d)
{
	std::string ret = "Deq: ";
	for (unsigned int i = 0; i < s_d.duke.size(); ++i)
	{
		if ((80 - 15 - 6) < ((i + 1) * (s_d.nbr_length + 1)))
		{
			ret += " [...]";
			break;
		}
		std::ostringstream oss;
		oss << " " << std::setw(s_d.nbr_length) << s_d.duke[i];
		ret += oss.str();
	}
	ret += "\n==DEBUG== pend:";
	for (unsigned int i = 0; i < s_d.duke_pend.size(); ++i)
	{
		if ((80 - 15 - 6) < ((i + 1) * (s_d.nbr_length + 1)))
		{
			ret += " [...]";
			break;
		}
		std::ostringstream oss;
		oss << " " << std::setw(s_d.nbr_length) << s_d.duke_pend[i];
		ret += oss.str();
	}
	ret += "\n==DEBUG== sort:";
	for (unsigned int i = 0; i < s_d.duke_sort.size(); ++i)
	{
		if ((80 - 15 - 6) < ((i + 1) * (s_d.nbr_length + 1)))
		{
			ret += " [...]";
			break;
		}
		std::ostringstream oss;
		oss << " " << std::setw(s_d.nbr_length) << s_d.duke_sort[i];
		ret += oss.str();
	}
	return (ret);
}

///////////////////////////////////////////////////////// Jacobsthal sequence //
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

////////////////////////////////////////////////////////////////////// Vector //
std::vector<int> merge_intertion_vec(t_vec &s_i)
{
	t_vec s_v;
	s_v.vicky		  = s_i.vicky;
	s_v.maximum_value = -1;
	for (size_t i = 0; i < s_v.vicky.size(); i++)
	{
		if (s_v.vicky[i] > s_v.maximum_value)
		{
			s_v.maximum_value = s_v.vicky[i];
		}
	}
	s_v.array_size = s_v.vicky.size();
	s_v.nbr_length = get_nbr_length(s_v.maximum_value);

	dprint("Before sorting: ");
	dprint(print_vec(s_v));
	dprint("");

	sort_pairs_vec(s_v);

	dprint("Inserting the element paired with the smallest number");
	s_v.vicky.insert(s_v.vicky.begin(), s_v.vicky_pend[0]);
	s_v.vicky_pend.erase(s_v.vicky_pend.begin());
	dprint(print_vec(s_v));
	dprint("");

	dprint("Inserting the remaining elements");
	s_v.vicky_sort = s_v.vicky;

	dprint("Insertion init");
	dprint(print_vec(s_v));
	insert_vec(s_v);
	dprint("Insertion finit");
	dprint("");

	dprint("After sorting: ");
	dprint(print_vec(s_v));
	dprint("");

	return (s_v.vicky_sort);
}

void insert_vec(t_vec &s_v)
{
	std::vector<unsigned int> jacob = get_jacob_vec();
	for (size_t k = 2; k < jacob.size(); k++)
	{
		int upper = jacob[k] - 2;
		int lower = jacob[k - 1] - 1;
		if (upper >= (int) s_v.vicky_pend.size())
		{
			upper = s_v.vicky_pend.size() - 1;
		}
		for (int idx = upper; idx >= lower; idx--)
		{
			int						   pend_val = s_v.vicky_pend[idx];
			std::vector<int>::iterator it_partner;
			if (idx + 2 < (int) s_v.vicky.size())
			{
				int partner_val = s_v.vicky[idx + 2];
				it_partner		= std::find(s_v.vicky_sort.begin(),
										s_v.vicky_sort.end(),
										partner_val);
			}
			else
			{
				it_partner = s_v.vicky_sort.end();
			}

			std::vector<int>::iterator pos
				= std::lower_bound(s_v.vicky_sort.begin(),
								   it_partner,
								   pend_val);
			size_t insert_i = pos - s_v.vicky_sort.begin();
			dprint("Inserting element " << pend_val << " at index "
										<< insert_i);
			s_v.vicky_sort.insert(pos, pend_val);

			std::string highlight = "Sort:";
			for (size_t i = 0; i < s_v.vicky_sort.size(); i++)
			{
				std::ostringstream oss;
				if (i == insert_i)
				{
					oss << " [" << s_v.vicky_sort[i] << "]";
				}
				else
				{
					oss << " " << s_v.vicky_sort[i];
				}
				highlight += oss.str();
				if (highlight.length() > 80 - 15 - 6 - 2)
				{
					highlight += " [...]";
					break;
				}
			}
			dprint(highlight);
		}
	}
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

	dprint("|||| Recursively call itself to order itself!");
	if (s_i.vicky.size() <= 1)
	{
		return;
	}

	std::vector<t_pair_o_int> pairs;
	size_t					  paired_count = s_i.vicky.size();
	for (size_t k = 0; k < paired_count; ++k)
	{
		pairs.push_back(std::make_pair(s_i.vicky[k], s_i.vicky_pend[k]));
	}

	t_vec next_level = s_i;
	next_level.vicky_pend.clear();
	next_level.vicky_sort.clear();

	dprint("|||| Recursion init:  " << s_i.array_size);
	s_i.vicky = merge_intertion_vec(next_level);
	dprint("|||| Recursion finit: " << s_i.array_size);

	std::vector<int> stragglers;
	for (size_t k = paired_count; k < s_i.vicky_pend.size(); ++k)
	{
		stragglers.push_back(s_i.vicky_pend[k]);
	}

	s_i.vicky_pend.clear();
	for (size_t k = 0; k < s_i.vicky.size(); ++k)
	{
		for (size_t j = 0; j < pairs.size(); ++j)
		{
			if (pairs[j].first == s_i.vicky[k])
			{
				s_i.vicky_pend.push_back(pairs[j].second);
				pairs.erase(pairs.begin() + j);
				break;
			}
		}
	}

	for (size_t k = 0; k < stragglers.size(); ++k)
	{
		s_i.vicky_pend.push_back(stragglers[k]);
	}
	dprint(print_vec(s_i));
	dprint("");
}

std::string print_vec(t_vec &s_i)
{
	std::string ret = "Vec: ";
	for (unsigned int i = 0; i < s_i.vicky.size(); ++i)
	{
		if ((80 - 15 - 6) < ((i + 1) * (s_i.nbr_length + 1)))
		{
			ret += " [...]";
			break;
		}
		std::ostringstream oss;
		oss << " " << std::setw(s_i.nbr_length) << s_i.vicky[i];
		ret += oss.str();
	}
	ret += "\n==DEBUG== pend:";
	for (unsigned int i = 0; i < s_i.vicky_pend.size(); ++i)
	{
		if ((80 - 15 - 6) < ((i + 1) * (s_i.nbr_length + 1)))
		{
			ret += " [...]";
			break;
		}
		std::ostringstream oss;
		oss << " " << std::setw(s_i.nbr_length) << s_i.vicky_pend[i];
		ret += oss.str();
	}
	ret += "\n==DEBUG== sort:";
	for (unsigned int i = 0; i < s_i.vicky_sort.size(); ++i)
	{
		if ((80 - 15 - 6) < ((i + 1) * (s_i.nbr_length + 1)))
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
