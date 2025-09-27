/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   Ice.cpp                              :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/09/20 16:44:06      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/09/20 16:44:13     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice()
{
    if (DEBUG)
    {
        std::cout << "Ice: Default Constructor\n";
    }
}

Ice::Ice(std::string const &type)
{
    if (DEBUG)
    {
        std::cout << "Ice: Parametrized Default Constructor\n";
    }
}

Ice::Ice(const Ice &other)
{
    if (DEBUG)
    {
        std::cout << "Ice: Copy Constructor\n";
    }
}

Ice &Ice::operator=(const Ice &other)
{
    if (DEBUG)
    {
        std::cout << "Ice: Copy Operator= Constructor\n";
    }
}

Ice::~Ice()
{
    if (DEBUG)
    {
        std::cout << "Ice: Destructor\n";
    }
}

void       Ice::use(ICharacter &target)
{
	if (DEBUG)
	{
		std::cout << "Ice: use()\n";
	}
}
