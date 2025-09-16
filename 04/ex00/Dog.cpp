/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   Dog.cpp                              :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/09/16 11:51:40      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/09/16 13:36:46     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include "Dog.hpp"

///////////////////////////////////////////////////// Canonical Orthodox Form //
Dog::Dog() : Animal("Dog")
{
	this->type_ = "Dog";
}

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
		std::cout << "It's similar to a previous " << type_ << ".\n";
	}
	return (*this);
}

Dog::~Dog()
{
}

/////////////////////////////////////////////////////////////////// Functions //
void Dog::makeSound() const
{
	std::cout << "The Dog barks. It's not very effective\n";
}
