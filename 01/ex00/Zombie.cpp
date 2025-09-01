/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   Zombie.cpp                           :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/08/31 13:57:40      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/09/01 13:32:10     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string baptism_name) : name(baptism_name)
{
}

void Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}

Zombie::~Zombie()
{
	std::cout << name << " is destroyed.\n";
}
