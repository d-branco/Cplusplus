/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   main.cpp                             :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/09/15 15:20:19      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/09/15 16:09:10     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>

#include "ClapTrap.hpp"

int main()
{
	ClapTrap tagarela("Balabolka");
	ClapTrap treta("Bladdermouth");

	std::cout << "\nNames: " << tagarela.get_name() << " and "
			  << treta.get_name() << "\n\n";

	tagarela.attack(treta.get_name());
	std::cout << "\n";

	treta.beRepaired(1);
	std::cout << "\n";

	std::cout << "Time passes.\nMetal rusts.\n";
	tagarela.takeDamage(10);
	treta.takeDamage(10);
	std::cout << "\n";

	tagarela.attack(treta.get_name());
	treta.attack(tagarela.get_name());
	std::cout << "\n";

	tagarela.beRepaired(0);
	for (int iterator = 0; iterator < 10; iterator++)
	{
		treta.beRepaired(1);
	}

	std::cout << "\n";
	return (EXIT_SUCCESS);
}
