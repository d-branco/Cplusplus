/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   Animal.cpp                           :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/09/16 17:20:42      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/09/16 18:42:52     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include "Animal.hpp"

///////////////////////////////////////////////////// Canonical Orthodox Form //
Animal::Animal()
{
	std::cout << "A wild animal appears!";
	if (!type_.empty())
	{
		std::cout << "It's a " << this->type_ << ".";
	}
	std::cout << "\n";
}

Animal::Animal(std::string type) : type_(type)
{
	std::cout << "A wild animal appears! It's a " << type_ << "!\n";
}

Animal::Animal(const Animal &other)
{
	*this = other;
}

Animal &Animal::operator=(const Animal &other)
{
	if (this != &other)
	{
		this->type_ = other.type_;
		std::cout << "Another " << type_ << " appears!\n";
	}
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Wild ";
	if (!this->type_.empty())
	{
		std::cout << this->type_;
	}
	else
	{
		std::cout << "animal";
	}
	std::cout << " fled!\n";
}

////////////////////////////////////////////////////////////////////// Getter //
std::string Animal::getType() const
{
	return (this->type_);
}

/////////////////////////////////////////////////////////////////// Functions //
void Animal::makeSound() const
{
	std::cout << "A wild animal made a sound.\n";
}
