/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   AAnimal.cpp                          :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/09/18 13:57:45      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/10/01 14:08:30     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include "AAnimal.hpp"

///////////////////////////////////////////////////// Canonical Orthodox Form //
Animal::Animal()
{
    std::cout << "Animal: Default Constructor: A wild animal appears!";
    if (!type_.empty())
    {
        std::cout << "It's a " << this->type_ << ".";
    }
    std::cout << "\n";
}

Animal::Animal(std::string type) : type_(type)
{
    std::cout << "Animal: Constructor with type argument: "
                 "A wild animal appears! It's a "
              << type_ << "!\n";
}

Animal::Animal(const Animal &other)
{
    std::cout << "Animal: Copy Constructor\n";
    *this = other;
}

Animal &Animal::operator=(const Animal &other)
{
    if (this == &other)
    {
        return (*this);
    }

    this->type_ = other.type_;
    std::cout << "Animal: Copy Operator= Constructor: "
                 "Another "
              << type_ << " appears!\n";

    return (*this);
}

Animal::~Animal()
{
    std::cout << "Animal: Destructor: Wild ";
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
// void Animal::makeSound() const
//{
//     std::cout << "Animal: A wild animal made a sound.\n";
// }
