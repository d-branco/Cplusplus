/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   WrongAnimal.cpp                      :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/09/16 13:43:25      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/09/16 13:52:39     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

///////////////////////////////////////////////////// Canonical Orthodox Form //
WrongAnimal::WrongAnimal()
{
	std::cout << "A wild animal appears!";
	if (!type_.empty())
	{
		std::cout << "It's a " << this->type_ << ".";
	}
	std::cout << "\n";
}

WrongAnimal::WrongAnimal(std::string type) : type_(type)
{
	std::cout << "A wild animal appears! It's a " << type_ << "!\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	*this = other;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	if (this != &other)
	{
		this->type_ = other.type_;
		std::cout << "Another " << type_ << " appears!\n";
	}
	return (*this);
}

WrongAnimal::~WrongAnimal()
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
std::string WrongAnimal::getType() const
{
	return (this->type_);
}

/////////////////////////////////////////////////////////////////// Functions //
void WrongAnimal::makeSound() const
{
	std::cout << "A wild animal made a sound. Something is wrong with it!\n";
}
