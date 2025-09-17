/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   WrongCat.cpp                         :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/09/16 13:40:05      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/09/16 13:55:05     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include "WrongCat.hpp"

///////////////////////////////////////////////////// Canonical Orthodox Form //
WrongCat::WrongCat() : WrongAnimal("Cat")
{
    this->type_ = "Cat";
}

WrongCat::WrongCat(std::string type) : WrongAnimal(type)
{
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other.type_)
{
    *this = other;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
    if (this != &other)
    {
        this->type_ = other.type_;
        std::cout << "It's similar to a previous " << type_ << ".\n";
    }
    return (*this);
}

WrongCat::~WrongCat()
{
}

/////////////////////////////////////////////////////////////////// Functions //
void WrongCat::makeSound() const
{
    std::cout << "The Cat caws. Sounds like a crow.\n";
}
