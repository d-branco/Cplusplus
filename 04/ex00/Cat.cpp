/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   Cat.cpp                              :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/09/16 12:31:03      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/09/16 12:53:10     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include "Cat.hpp"

///////////////////////////////////////////////////// Canonical Orthodox Form //
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
		std::cout << "It's similar to the previous " << type_ << ".\n";
	}
	return (*this);
}

Cat::~Cat()
{
}
