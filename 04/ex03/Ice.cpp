/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   Ice.cpp                              :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/09/27 16:01:11      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/09/27 16:07:38     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	if (DEBUG)
	{
		std::cout << "Ice: Default Constructor\n";
	}
}

// Ice::Ice(std::string const &type)
// {
//     if (DEBUG)
//     {
//         std::cout << "Ice: Parametrized Default Constructor\n";
//     }
// }

Ice::Ice(const Ice &other) : AMateria(other.type_)
{
	if (DEBUG)
	{
		std::cout << "Ice: Copy Constructor\n";
	}

	*this = other;
}

Ice &Ice::operator=(const Ice &other)
{
	if (DEBUG)
	{
		std::cout << "Ice: Copy Operator= Constructor\n";
	}
	if (this == &other)
	{
		if (DEBUG)
		{
			std::cout << "     Copying itself!\n";
		}
		return (*this);
	}

	return (*this);
}

Ice::~Ice()
{
	if (DEBUG)
	{
		std::cout << "Ice: Destructor\n";
	}
}

AMateria *Ice::clone() const
{
	if (DEBUG)
	{
		std::cout << "Ice: Clone()\n";
	}

	AMateria *clone = new Ice(*this);

	return (clone);
}

void Ice::use(ICharacter &target)
{
	if (DEBUG)
	{
		std::cout << "Ice: use()\n";
	}

	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}
