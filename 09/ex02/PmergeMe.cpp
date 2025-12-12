/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   PmergeMe.cpp                         :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/12/03 12:09:12      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/12/12 15:42:06     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/////////////////////////////////////////////////////////////////////// Deque //
PmergeMeDeq::PmergeMeDeq() : maximum_value_(-1), array_size_(0), nbr_length_(0)
{
}

PmergeMeDeq::PmergeMeDeq(const PmergeMeDeq &src)
{
	*this = src;
}

PmergeMeDeq::~PmergeMeDeq()
{
}

PmergeMeDeq &PmergeMeDeq::operator=(const PmergeMeDeq &rhs)
{
	if (this != &rhs)
	{
		maximum_value_ = rhs.maximum_value_;
		array_size_	   = rhs.array_size_;
		nbr_length_	   = rhs.nbr_length_;
		deq_		   = rhs.deq_;
		pend_		   = rhs.pend_;
		sort_		   = rhs.sort_;
	}
	return *this;
}

void PmergeMeDeq::push_back(int val)
{
	deq_.push_back(val);
}

std::deque<int> &PmergeMeDeq::getDeq()
{
	return deq_;
}

size_t PmergeMeDeq::getSize() const
{
	return deq_.size();
}

int PmergeMeDeq::getNbrLength() const
{
	return nbr_length_;
}

int PmergeMeDeq::getMax() const
{
	return maximum_value_;
}

void PmergeMeDeq::setMax(int val)
{
	maximum_value_ = val;
}

void PmergeMeDeq::setNbrLength(int val)
{
	nbr_length_ = val;
}

std::deque<int> PmergeMeDeq::run()
{
	maximum_value_ = -1;
	for (size_t i = 0; i < deq_.size(); i++)
	{
		if (deq_[i] > maximum_value_)
		{
			maximum_value_ = deq_[i];
		}
	}
	array_size_ = deq_.size();
	nbr_length_ = calcNbrLength(maximum_value_);

	dprint("Before sorting: ");
	dprint(print());
	dprint("");

	sortPairs();

	dprint("Inserting the element paired with the smallest number");
	deq_.insert(deq_.begin(), pend_[0]);
	pend_.erase(pend_.begin());
	dprint(print());
	dprint("");

	dprint("Inserting the remaining elements");
	sort_ = deq_;

	dprint("Insertion init");
	dprint(print());
	insert();
	dprint("Insertion finit");
	dprint("");

	dprint("After sorting: ");
	dprint(print());
	dprint("");

	return (sort_);
}

std::string PmergeMeDeq::print()
{
	std::string ret = "Deq: ";
	for (unsigned int i = 0; i < deq_.size(); ++i)
	{
		if ((80 - 15 - 6) < ((i + 1) * (nbr_length_ + 1)))
		{
			ret += " [...]";
			break;
		}
		std::ostringstream oss;
		oss << " " << std::setw(nbr_length_) << deq_[i];
		ret += oss.str();
	}
	ret += "\n==DEBUG== pend:";
	for (unsigned int i = 0; i < pend_.size(); ++i)
	{
		if ((80 - 15 - 6) < ((i + 1) * (nbr_length_ + 1)))
		{
			ret += " [...]";
			break;
		}
		std::ostringstream oss;
		oss << " " << std::setw(nbr_length_) << pend_[i];
		ret += oss.str();
	}
	ret += "\n==DEBUG== sort:";
	for (unsigned int i = 0; i < sort_.size(); ++i)
	{
		if ((80 - 15 - 6) < ((i + 1) * (nbr_length_ + 1)))
		{
			ret += " [...]";
			break;
		}
		std::ostringstream oss;
		oss << " " << std::setw(nbr_length_) << sort_[i];
		ret += oss.str();
	}
	return (ret);
}

void PmergeMeDeq::insert()
{
	std::vector<unsigned int> jacob = getJacobVec();
	for (size_t k = 3; k < jacob.size(); k++)
	{
		int upper = jacob[k] - 2;
		int lower = jacob[k - 1] - 1;
		if (lower >= (int) pend_.size())
		{
			break;
		}
		if (upper >= (int) pend_.size())
		{
			upper = pend_.size() - 1;
		}
		dprint("Range of elements to pair: " << lower << " to " << upper);

		for (int idx = upper; idx >= lower; idx--)
		{
			int						  pend_val = pend_[idx];
			std::deque<int>::iterator it_partner;
			if (idx + 2 < (int) deq_.size())
			{
				int partner_val = deq_[idx + 2];
				it_partner = std::find(sort_.begin(), sort_.end(), partner_val);
			}
			else
			{
				it_partner = sort_.end();
			}

			std::deque<int>::iterator pos
				= std::lower_bound(sort_.begin(), it_partner, pend_val);
			size_t insert_i = pos - sort_.begin();
			dprint("Inserting element " << pend_val << " at index "
										<< insert_i);
			sort_.insert(pos, pend_val);

			std::string highlight = "pend:";
			for (int i = 0; i < (int) pend_.size(); i++)
			{
				std::ostringstream oss;
				if (i == lower)
				{
					oss << " [" << pend_[i];
				}
				else if (i == upper)
				{
					oss << " " << pend_[i] << "]";
				}
				else
				{
					oss << " " << pend_[i];
				}
				highlight += oss.str();
				if ((int) highlight.length()
					> 80 - 15 - 6 - 2 * (upper - lower + 1))
				{
					highlight += " [...]";
					break;
				}
			}
			dprint(highlight);
			highlight = "sort:";
			for (size_t i = 0; i < sort_.size(); i++)
			{
				std::ostringstream oss;
				if (i == insert_i)
				{
					oss << " [" << sort_[i] << "]";
				}
				else
				{
					oss << " " << sort_[i];
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

void PmergeMeDeq::sortPairs()
{
	dprint("Sorting the pairs");
	for (size_t i = 0; i + 2 <= deq_.size(); i++)
	{
		if (deq_[i] > deq_[i + 1])
		{
			pend_.push_back(deq_[i + 1]);
			deq_.erase(deq_.begin() + i + 1);
		}
		else
		{
			pend_.push_back(deq_[i]);
			deq_.erase(deq_.begin() + i);
		}
	}
	size_t tmp_size = pend_.size();
	while (deq_.size() > tmp_size)
	{
		pend_.push_back(deq_[(deq_.size() - 1)]);
		deq_.pop_back();
	}
	dprint(print());
	dprint("");

	dprint("|||| Recursively call itself to order itself!");
	if (deq_.size() <= 1)
	{
		return;
	}

	std::deque<t_pair_o_int> pairs;
	size_t					 n_pairs = deq_.size();
	for (size_t k = 0; k < n_pairs; ++k)
	{
		pairs.push_back(std::make_pair(deq_[k], pend_[k]));
	}

	PmergeMeDeq next_level = *this;
	next_level.pend_.clear();
	next_level.sort_.clear();

	dprint("|||| Recursion init:  " << array_size_);
	deq_ = next_level.run();
	dprint("|||| Recursion finit: " << array_size_);

	std::deque<int> remaining;
	for (size_t k = n_pairs; k < pend_.size(); ++k)
	{
		remaining.push_back(pend_[k]);
	}

	pend_.clear();
	for (size_t k = 0; k < deq_.size(); ++k)
	{
		for (size_t j = 0; j < pairs.size(); ++j)
		{
			if (pairs[j].first == deq_[k])
			{
				pend_.push_back(pairs[j].second);
				pairs.erase(pairs.begin() + j);
				break;
			}
		}
	}

	for (size_t k = 0; k < remaining.size(); ++k)
	{
		pend_.push_back(remaining[k]);
	}
	dprint(print());
	dprint("");
}

std::vector<unsigned int> PmergeMeDeq::getJacobVec()
{
	static const unsigned int array[]
		= {0,		  1,		 1,			3,		  5,		11,
		   21,		  43,		 85,		171,	  341,		683,
		   1365,	  2731,		 5461,		10923,	  21845,	43691,
		   87381,	  174763,	 349525,	699051,	  1398101,	2796203,
		   5592405,	  11184811,	 22369621,	44739243, 89478485, 178956971,
		   357913941, 715827883, 1431655765};

	return std::vector<unsigned int>(array,
									 array + sizeof(array) / sizeof(array[0]));
}

int PmergeMeDeq::calcNbrLength(int nbr)
{
	int len = 0;
	if (nbr < 0)
	{
		len++;
		nbr = -nbr;
	}
	if (nbr == 0)
	{
		return 1;
	}
	while (nbr > 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

////////////////////////////////////////////////////////////////////// Vector //
PmergeMeVec::PmergeMeVec() : maximum_value_(-1), array_size_(0), nbr_length_(0)
{
}

PmergeMeVec::PmergeMeVec(const PmergeMeVec &src)
{
	*this = src;
}

PmergeMeVec::~PmergeMeVec()
{
}

PmergeMeVec &PmergeMeVec::operator=(const PmergeMeVec &rhs)
{
	if (this != &rhs)
	{
		maximum_value_ = rhs.maximum_value_;
		array_size_	   = rhs.array_size_;
		nbr_length_	   = rhs.nbr_length_;
		vec_		   = rhs.vec_;
		pend_		   = rhs.pend_;
		sort_		   = rhs.sort_;
	}
	return *this;
}

void PmergeMeVec::push_back(int val)
{
	vec_.push_back(val);
}

std::vector<int> &PmergeMeVec::getVec()
{
	return vec_;
}

size_t PmergeMeVec::getSize() const
{
	return vec_.size();
}

int PmergeMeVec::getNbrLength() const
{
	return nbr_length_;
}

int PmergeMeVec::getMax() const
{
	return maximum_value_;
}

void PmergeMeVec::setMax(int val)
{
	maximum_value_ = val;
}

void PmergeMeVec::setNbrLength(int val)
{
	nbr_length_ = val;
}

std::vector<int> PmergeMeVec::run()
{
	maximum_value_ = -1;
	for (size_t i = 0; i < vec_.size(); i++)
	{
		if (vec_[i] > maximum_value_)
		{
			maximum_value_ = vec_[i];
		}
	}
	array_size_ = vec_.size();
	nbr_length_ = calcNbrLength(maximum_value_);

	dprint("Before sorting: ");
	dprint(print());
	dprint("");

	sortPairs();

	dprint("Inserting the element paired with the smallest number");
	vec_.insert(vec_.begin(), pend_[0]);
	pend_.erase(pend_.begin());
	dprint(print());
	dprint("");

	dprint("Inserting the remaining elements");
	sort_ = vec_;

	dprint("Insertion init");
	dprint(print());
	dprint("");
	insert();
	dprint("Insertion finit");
	dprint("");

	dprint("After sorting: ");
	dprint(print());
	dprint("");

	return (sort_);
}

void PmergeMeVec::insert()
{
	std::vector<unsigned int> jacob = getJacobVec();
	for (size_t k = 3; k < jacob.size(); k++)
	{
		int upper = jacob[k] - 2;
		int lower = jacob[k - 1] - 1;
		if (lower >= (int) pend_.size())
		{
			break;
		}
		if (upper >= (int) pend_.size())
		{
			upper = pend_.size() - 1;
		}
		dprint("Range of elements to pair: " << lower << " to " << upper);

		for (int idx = upper; idx >= lower; idx--)
		{
			int						   pend_val = pend_[idx];
			std::vector<int>::iterator it_partner;
			if (idx + 2 < (int) vec_.size())
			{
				int partner_val = vec_[idx + 2];
				it_partner = std::find(sort_.begin(), sort_.end(), partner_val);
			}
			else
			{
				it_partner = sort_.end();
			}

			std::vector<int>::iterator pos
				= std::lower_bound(sort_.begin(), it_partner, pend_val);
			size_t insert_i = pos - sort_.begin();
			dprint("Inserting element " << pend_val << " at index "
										<< insert_i);
			sort_.insert(pos, pend_val);

			std::string highlight = "pend:";
			for (int i = 0; i < (int) pend_.size(); i++)
			{
				std::ostringstream oss;
				if (i == lower)
				{
					oss << " [" << pend_[i];
				}
				else if (i == upper)
				{
					oss << " " << pend_[i] << "]";
				}
				else
				{
					oss << " " << pend_[i];
				}
				highlight += oss.str();
				if ((int) highlight.length()
					> 80 - 15 - 6 - 2 * (upper - lower + 1))
				{
					highlight += " [...]";
					break;
				}
			}
			dprint(highlight);
			highlight = "sort:";
			for (size_t i = 0; i < sort_.size(); i++)
			{
				std::ostringstream oss;
				if (i == insert_i)
				{
					oss << " [" << sort_[i] << "]";
				}
				else
				{
					oss << " " << sort_[i];
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

void PmergeMeVec::sortPairs()
{
	dprint("Sorting the pairs");
	for (size_t i = 0; i + 2 <= vec_.size(); i++)
	{
		if (vec_[i] > vec_[i + 1])
		{
			pend_.push_back(vec_[i + 1]);
			vec_.erase(vec_.begin() + i + 1);
		}
		else
		{
			pend_.push_back(vec_[i]);
			vec_.erase(vec_.begin() + i);
		}
	}
	size_t tmp_size = pend_.size();
	while (vec_.size() > tmp_size)
	{
		pend_.push_back(vec_[(vec_.size() - 1)]);
		vec_.erase(vec_.end() - 1);
	}
	dprint(print());
	dprint("");

	dprint("|||| Recursively call itself to order itself!");
	if (vec_.size() <= 1)
	{
		return;
	}

	std::vector<t_pair_o_int> pairs;
	size_t					  n_pairs = vec_.size();
	for (size_t k = 0; k < n_pairs; ++k)
	{
		pairs.push_back(std::make_pair(vec_[k], pend_[k]));
	}

	PmergeMeVec next_level = *this;
	next_level.pend_.clear();
	next_level.sort_.clear();

	dprint("|||| Recursion init:  " << array_size_);
	vec_ = next_level.run();
	dprint("|||| Recursion finit: " << array_size_);

	std::vector<int> remaining;
	for (size_t k = n_pairs; k < pend_.size(); ++k)
	{
		remaining.push_back(pend_[k]);
	}

	pend_.clear();
	for (size_t k = 0; k < vec_.size(); ++k)
	{
		for (size_t j = 0; j < pairs.size(); ++j)
		{
			if (pairs[j].first == vec_[k])
			{
				pend_.push_back(pairs[j].second);
				pairs.erase(pairs.begin() + j);
				break;
			}
		}
	}

	for (size_t k = 0; k < remaining.size(); ++k)
	{
		pend_.push_back(remaining[k]);
	}
	dprint(print());
	dprint("");
}

std::string PmergeMeVec::print()
{
	std::string ret = "Vec: ";
	for (unsigned int i = 0; i < vec_.size(); ++i)
	{
		if ((80 - 15 - 6) < ((i + 1) * (nbr_length_ + 1)))
		{
			ret += " [...]";
			break;
		}
		std::ostringstream oss;
		oss << " " << std::setw(nbr_length_) << vec_[i];
		ret += oss.str();
	}
	ret += "\n==DEBUG== pend:";
	for (unsigned int i = 0; i < pend_.size(); ++i)
	{
		if ((80 - 15 - 6) < ((i + 1) * (nbr_length_ + 1)))
		{
			ret += " [...]";
			break;
		}
		std::ostringstream oss;
		oss << " " << std::setw(nbr_length_) << pend_[i];
		ret += oss.str();
	}
	ret += "\n==DEBUG== sort:";
	for (unsigned int i = 0; i < sort_.size(); ++i)
	{
		if ((80 - 15 - 6) < ((i + 1) * (nbr_length_ + 1)))
		{
			ret += " [...]";
			break;
		}
		std::ostringstream oss;
		oss << " " << std::setw(nbr_length_) << sort_[i];
		ret += oss.str();
	}
	return (ret);
}

std::vector<unsigned int> PmergeMeVec::getJacobVec()
{
	static const unsigned int array[]
		= {0,		  1,		 1,			3,		  5,		11,
		   21,		  43,		 85,		171,	  341,		683,
		   1365,	  2731,		 5461,		10923,	  21845,	43691,
		   87381,	  174763,	 349525,	699051,	  1398101,	2796203,
		   5592405,	  11184811,	 22369621,	44739243, 89478485, 178956971,
		   357913941, 715827883, 1431655765};

	return std::vector<unsigned int>(array,
									 array + sizeof(array) / sizeof(array[0]));
}

int PmergeMeVec::calcNbrLength(int nbr)
{
	int len = 0;
	if (nbr < 0)
	{
		len++;
		nbr = -nbr;
	}
	if (nbr == 0)
	{
		return 1;
	}
	while (nbr > 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}
