/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   main.cpp                             :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/08/31 11:37:59      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/08/31 11:53:04     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *newZombie(std::string name);
void	randomChump(std::string name);

int		main()
{
	randomChump("Alice");

	Zombie *ptr = newZombie("Bob");
	ptr->announce();
	delete ptr;
}
