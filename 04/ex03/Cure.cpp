/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   Cure.cpp                             :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/09/20 16:44:27      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/09/20 16:44:29     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
    if (DEBUG)
    {
        std::cout << "Cure: Default Constructor\n";
    }
}

// Cure::Cure(std::string const &type)
// {
//     if (DEBUG)
//     {
//         std::cout << "Cure: Parametrized Default Constructor\n";
//     }
// }

Cure::Cure(const Cure &other)
{
    if (DEBUG)
    {
        std::cout << "Cure: Copy Constructor\n";
    }

    *this = other;
}

Cure &Cure::operator=(const Cure &other)
{
    if (DEBUG)
    {
        std::cout << "Cure: Copy Operator= Constructor\n";
    }
    if (this == &other)
    {
        if (DEBUG)
        {
            std::cout << "      Copying itself!\n";
        }
        return (*this);
    }
}

Cure::~Cure()
{
    if (DEBUG)
    {
        std::cout << "Cure: Destructor\n";
    }
}

AMateria *Cure::clone() const
{
    if (DEBUG)
    {
        std::cout << "Cure: Clone()\n";
    }

    AMateria *clone = new Cure(*this);

    return (clone);
}

void Cure::use(ICharacter &target)
{
    if (DEBUG)
    {
        std::cout << "Cure: use()\n";
    }

    std::cout << "* heals " << target.getName() << "\'s wouds *\n";
}
