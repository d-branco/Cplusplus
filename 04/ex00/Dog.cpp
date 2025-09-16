/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   Dog.cpp                              :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/09/16 11:51:40      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/09/16 12:53:13     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include "Dog.hpp"

///////////////////////////////////////////////////// Canonical Orthodox Form //
Dog::Dog(std::string type) : Animal(type)
{
}

Dog::Dog(const Dog &other) : Animal(other.type_)
{
	*this = other;
}

Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		this->type_ = other.type_;
		std::cout << "It's similar to the previous " << type_ << ".\n";
	}
	return (*this);
}

Dog::~Dog()
{
}
