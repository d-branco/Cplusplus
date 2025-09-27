/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   AMateria.cpp                         :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/09/27 11:38:23      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/09/27 11:38:39     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
	if (DEBUG)
	{
		std::cout << "AMateria: Default Constructor\n";
	}
	std::cout << "\nError:\nThis line should not be reached!\n\n";
}

AMateria::AMateria(std::string const &type) : type_(type)
{
	if (DEBUG)
	{
		std::cout << "AMateria: Parametrized Default Constructor\n";
		std::cout << "          type_: " << type_ << "\n";
	}
}

AMateria::AMateria(const AMateria &other)
{
	if (DEBUG)
	{
		std::cout << "AMateria: Copy Constructor\n";
		std::cout << "          type_: " << other.type_ << "\n";
	}
}

AMateria &AMateria::operator=(const AMateria &other)
{
	if (DEBUG)
	{
		std::cout << "AMateria: Copy Operator= Constructor\n";
		std::cout << "          Copying: " << other.getType() << "\n";
	}

	// The subject warns not to do this:
	// this->type_ = other.type_;

	return (*this);
}

AMateria::~AMateria()
{
	if (DEBUG)
	{
		std::cout << "AMateria: Destructor\n";
	}
}

std::string const &AMateria::getType() const
{
	//if (DEBUG)
	//{
	//	std::cout << "AMateria: getType()\n";
	//}

	return (this->type_);
}

void AMateria::use(ICharacter &target)
{
	if (DEBUG)
	{
		std::cout << "AMateria: use(" << target.getName() << ")\n";
	}
}
