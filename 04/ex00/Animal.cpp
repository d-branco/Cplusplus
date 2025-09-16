/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   Animal.cpp                           :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/09/16 11:17:06      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/09/16 11:46:42     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include "Animal.hpp"

///////////////////////////////////////////////////// Canonical Orthodox Form //
Animal::Animal(std::string type) : type_(type)
{
	std::cout << "A wild " << type_ << " appears!\n";
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
	std::cout << "Wild " << type_ << " fled!\n";
}
