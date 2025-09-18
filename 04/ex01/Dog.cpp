/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   Dog.cpp                              :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/09/18 08:09:18      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/09/18 09:33:49     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include "Dog.hpp"

///////////////////////////////////////////////////// Canonical Orthodox Form //
Dog::Dog() : Animal("Dog")
{
    std::cout << " └─ Dog: Default Constructor.\n";
    this->type_      = "Dog";
    this->dog_brain_ = new Brain;
}

Dog::Dog(std::string type) : Animal(type)
{
    std::cout << " └─ Dog: Default Constructor with type argument.\n";
    this->dog_brain_ = new Brain;
}

Dog::Dog(const Dog &other) : Animal(other.type_)
{
    std::cout << " └─ Dog: Copy Constructor.\n";
    dog_brain_ = new Brain(*(other.dog_brain_));
}

Dog &Dog::operator=(const Dog &other)
{
    std::cout << " └─ Dog: Copy Operator= Constructor: ";
    if (this == &other)
    {
        return (*this);
    }

    this->type_ = other.type_;
    delete dog_brain_;
    dog_brain_ = new Brain(*(other.dog_brain_));
    std::cout << " └─ It's similar to a previous " << type_ << ".\n";

    return (*this);
}

Dog::~Dog()
{
    std::cout << "Dog: Deconstructor.\n";
    delete (dog_brain_);
    std::cout << " └───── ";
}

/////////////////////////////////////////////////////////////////// Functions //
void Dog::makeSound() const
{
    std::cout << "The Dog barks. It's not very effective\n";
}

std::string Dog::get_brain_idea(size_t index)
{
    return ((*dog_brain_)[index]);
}

const std::string Dog::get_brain_idea(size_t index) const
{
    return ((*dog_brain_)[index]);
}

void Dog::set_brain_idea(size_t index, std::string str)
{
    (*dog_brain_)[index] = str;
}
