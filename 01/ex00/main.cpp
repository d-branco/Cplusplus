/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   main.cpp                             :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/08/31 13:57:40      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/09/01 13:32:56     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *newZombie(std::string name);
void	randomChump(std::string name);

int		main()
{
	Zombie *ptr = newZombie("Alice");
	ptr->announce();

	randomChump("Bob");

	delete ptr;
}
