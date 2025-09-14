/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   Zombie.cpp                           :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/08/31 11:37:59      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/08/31 15:42:48     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string baptism_name) : name(baptism_name), horde(NULL)
{
}

Zombie::Zombie()
{
}

void Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}

void Zombie::set_name(std::string name)
{
	this->name = name;
}

std::string Zombie::get_name()
{
	return (name);
}
