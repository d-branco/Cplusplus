/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   Span.cpp                             :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/11/27 14:33:02      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/11/27 17:31:00     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include "Span.hpp"

///////////////////////////////////////////////////// Canonical Orthodox Form //
Span::Span(unsigned int ene) : ene_(ene)
{
	if (DEBUG)
	{
		std::cout << "==DEBUG== Span: Default Parametrized Constructor: N: "
				  << ene_ << "\n";
	}
}

Span::Span(const Span &other) : ene_(other.ene_), vec_(other.vec_)
{
	if (DEBUG)
	{
		std::cout << "==DEBUG== Span: Copy Constructor\n";
	}
	*this = other;
}

Span &Span::operator=(const Span &other)
{
	if (DEBUG)
	{
		std::cout << "==DEBUG== Span: Copy Operator Constructor\n";
	}
	if (this == &other)
	{
		return (*this);
	}
	ene_ = other.ene_;
	vec_ = other.vec_;

	return (*this);
}

Span::~Span()
{
	if (DEBUG)
	{
		std::cout << "==DEBUG== Span: Destructor\n";
	}
}

///////////////////////////////////////////////////////////////////// Getters //
///////////////////////////////////////////////////////////////////// Setters //
/////////////////////////////////////////////////////////////////// Functions //
void Span::addNumber(int nbr)
{
	if (DEBUG)
	{
		std::cout << "==DEBUG== Span: addNumber(" << nbr << ") trying...";
	}
	try
	{
		if (vec_.size() >= ene_)
		{
			throw std::exception();
		}
		vec_.push_back(nbr);
		if (DEBUG)
		{
			std::cout << " SUCCESS! Vector size: " << vec_.size() << "\n";
		}
	}
	catch (const std::exception &e)
	{
		if (DEBUG)
		{
			std::cout << "\n";
		}
		std::cout << "Error:\n  Maximum INT stored already (" << ene_ << ")\n";
	}
}

unsigned int Span::shortestSpan()
{
	if (DEBUG)
	{
		std::cout << "==DEBUG== Span: shortestspan()\n";
	}
	unsigned int span = 0;
	try
	{
		if (vec_.size() < 2)
		{
			throw std::exception();
		}
		std::vector<int> temp_vec = vec_;
		if (DEBUG)
		{
			std::cout << "==DEBUG== Span: shortestspan(): Original vector: ";
			unsigned int iii = 0;
			for (;;)
			{
				std::cout << vec_[iii] << ", ";
				iii++;
				if (iii >= (vec_.size() - 1))
				{
					break;
				}
			}
			std::cout << vec_[iii] << "\n";
		}
		std::sort(temp_vec.begin(), temp_vec.end());
		if (DEBUG)
		{
			std::cout << "==DEBUG== Span: shortestspan(): Sorted vector:   ";
			unsigned int iii = 0;
			for (;;)
			{
				std::cout << temp_vec[iii] << ", ";
				iii++;
				if (iii >= (temp_vec.size() - 1))
				{
					break;
				}
			}
			std::cout << temp_vec[iii] << "\n";
		}
		unsigned int iii = 1;
		span			 = temp_vec[1] - temp_vec[0];
		if (DEBUG)
		{
			std::cout << "==DEBUG== Span: shortespan(): new minimum: " << span
					  << " (between " << temp_vec[1] << " and " << temp_vec[0]
					  << ")\n";
		}
		for (;;)
		{
			if (span > (unsigned int) (temp_vec[iii + 1] - temp_vec[iii]))
			{
				span = temp_vec[iii + 1] - temp_vec[iii];
				if (DEBUG)
				{
					std::cout
						<< "==DEBUG== Span: shortespan(): new minimum: " << span
						<< " (between " << temp_vec[iii + 1] << " and "
						<< temp_vec[iii] << ")\n";
				}
			}
			iii++;
			if (iii >= vec_.size() - 2)
			{
				break;
			}
		}
	}
	catch (const std::exception &e)
	{
		std::cout << "Error:\n  Too few INT in vector (" << vec_.size()
				  << ")\n";
	}

	return (span);
}

unsigned int Span::longestSpan()
{
	if (DEBUG)
	{
		std::cout << "==DEBUG== Span: longestspan()\n";
	}
	try
	{
		if (vec_.size() < 2)
		{
			throw std::exception();
		}
	}
	catch (const std::exception &e)
	{
		std::cout << "Error:\n  Too few INT in vector (" << vec_.size()
				  << ")\n";
	}

	return (0);
}
