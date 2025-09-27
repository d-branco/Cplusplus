/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   AMateria.cpp                         :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/09/18 17:34:41      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/09/18 17:35:15     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
    if (DEBUG)
    {
        std::cout << "AMateria: Default Constructor\n";
    }
}

AMateria::AMateria(std::string const &type)
{
    if (DEBUG)
    {
        std::cout << "AMateria: Parametrized Default Constructor\n";
    }
}

AMateria::AMateria(const AMateria &other)
{
    if (DEBUG)
    {
        std::cout << "AMateria: Copy Constructor\n";
    }
}

AMateria &AMateria::operator=(const AMateria &other)
{
    if (DEBUG)
    {
        std::cout << "AMateria: Copy Operator= Constructor\n";
    }
}

AMateria::~AMateria()
{
    if (DEBUG)
    {
        std::cout << "AMateria: Destructor\n";
    }
}

std::string const &AMateria::getType() const // Returns the materia type
{
    if (DEBUG)
    {
        std::cout << "AMateria: getType()\n";
    }

    return (this->type_);
}

void       AMateria::use(ICharacter &target)
{
	if (DEBUG)
	{
		std::cout << "AMateria: use()\n";
	}
}