/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   Cat.cpp                              :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/09/16 17:20:42      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/09/16 17:23:35     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include "Cat.hpp"

///////////////////////////////////////////////////// Canonical Orthodox Form //
Cat::Cat() : Animal("Cat")
{
	this->type_ = "Cat";
}

Cat::Cat(std::string type) : Animal(type)
{
}

Cat::Cat(const Cat &other) : Animal(other.type_)
{
	*this = other;
}

Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		this->type_ = other.type_;
		std::cout << "  └── It's similar to a previous " << type_ << ".\n";
	}
	return (*this);
}

Cat::~Cat()
{
}

/////////////////////////////////////////////////////////////////// Functions //
void Cat::makeSound() const
{
	std::cout << "The Cat meows. It's not very effective\n";
}
