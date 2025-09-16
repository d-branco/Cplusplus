/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   Brain.cpp                            :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/09/16 15:56:45      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/09/16 16:03:05     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include "Brain.hpp"

///////////////////////////////////////////////////// Canonical Orthodox Form //
Brain::Brain() : ideas_(new std::string[100])
{
}

Brain::Brain(const Brain &other)
{
	*this = other;
}

Brain &Brain::operator=(const Brain &other)
{
	if (this != &other)
	{
		this->ideas_ = other.ideas_;
	}
	return (*this);
}

Brain::~Brain()
{
}

/////////////////////////////////////////////////////////////////// Functions //
std::string &Brain::operator[](size_t index)
{
	return this->ideas_[index];
}

const std::string &Brain::operator[](size_t index) const
{
	return this->ideas_[index];
}
