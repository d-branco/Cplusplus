/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   Cat.cpp                              :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/09/17 15:12:24      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/09/17 15:20:55     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include "Cat.hpp"

///////////////////////////////////////////////////// Canonical Orthodox Form //
Cat::Cat() : Animal("Cat")
{
    this->type_      = "Cat";
    this->cat_brain_ = new Brain;
}

Cat::Cat(std::string type) : Animal(type)
{
    this->cat_brain_ = new Brain;
}

Cat::Cat(const Cat &other) : Animal(other.type_)
{
    *this = other;
}

Cat &Cat::operator=(const Cat &other)
{
    if (this == &other)
    {
        return (*this);
    }

    this->type_ = other.type_;
    std::cout << "  └── It's similar to a previous " << type_ << ".\n";

    return (*this);
}

Cat::~Cat()
{
    delete (cat_brain_);
}

/////////////////////////////////////////////////////////////////// Functions //
void Cat::makeSound() const
{
    std::cout << "The Cat meows. It's not very effective\n";
}
