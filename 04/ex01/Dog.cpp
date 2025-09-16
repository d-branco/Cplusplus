/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   Dog.cpp                              :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/09/16 17:20:42      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/09/16 18:28:55     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include "Dog.hpp"

///////////////////////////////////////////////////// Canonical Orthodox Form //
Dog::Dog() : Animal("Dog")
{
	this->type_		 = "Dog";
	this->dog_brain_ = new Brain;
}

Dog::Dog(std::string type) : Animal(type)
{
	this->dog_brain_ = new Brain;
}

Dog::Dog(const Dog &other) : Animal(other.type_)
{
	dog_brain_ = new Brain(*(other.dog_brain_));
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		delete dog_brain_;
		dog_brain_ = new Brain(*(other.dog_brain_));
		std::cout << "  └── It's similar to a previous " << type_ << ".\n";
	}
	return (*this);
}

Dog::~Dog()
{
	delete (dog_brain_);
}

/////////////////////////////////////////////////////////////////// Functions //
void Dog::makeSound() const
{
	std::cout << "The Dog barks. It's not very effective\n";
}
