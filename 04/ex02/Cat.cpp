/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   Cat.cpp                              :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/09/18 08:10:08      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/09/18 09:33:57     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include "Cat.hpp"

///////////////////////////////////////////////////// Canonical Orthodox Form //
Cat::Cat() : Animal("Cat")
{
    std::cout << " └─ Cat: Default Constructor.\n";
    this->type_      = "Cat";
    this->cat_brain_ = new Brain;
}

Cat::Cat(std::string type) : Animal(type)
{
    std::cout << " └─ Cat: Default Constructor with type argument.\n";
    this->cat_brain_ = new Brain;
}

Cat::Cat(const Cat &other) : Animal(other.type_)
{
    std::cout << " └─ Cat: Copy Constructor.\n";
    cat_brain_ = new Brain(*(other.cat_brain_));
}

Cat &Cat::operator=(const Cat &other)
{
    std::cout << " └─ Cat: Copy Operator= Constructor: ";
    if (this == &other)
    {
        return (*this);
    }

    this->type_ = other.type_;
    delete cat_brain_;
    cat_brain_ = new Brain(*(other.cat_brain_));

    std::cout << "It's similar to a previous " << type_ << ".\n";

    return (*this);
}

Cat::~Cat()
{
    std::cout << "Cat: Deconstructor.\n";
    delete (cat_brain_);
    std::cout << " └───── ";
}

/////////////////////////////////////////////////////////////////// Functions //
void Cat::makeSound() const
{
    std::cout << "Cat: The Cat meows. It's not very effective\n";
}
