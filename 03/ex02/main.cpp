/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   main.cpp                             :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/09/16 05:57:08      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/09/16 05:58:28     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ClapTrap tagarela("Balabolka");
	ScavTrap treta("Bladdermouth");

	std::cout << "\nNames: " << tagarela.get_name() << " and "
			  << treta.get_name() << "\n\n";

	tagarela.attack(treta.get_name());
	std::cout << "\n";

	treta.beRepaired(1);
	std::cout << "\n";

	std::cout << "Time passes. Metal rusts.\n";
	tagarela.takeDamage(10);
	treta.takeDamage(10);
	std::cout << "\n";

	tagarela.attack(treta.get_name());
	treta.attack(tagarela.get_name());
	std::cout << "\n";

	tagarela.beRepaired(1);
	treta.beRepaired(1);
	std::cout << "\n";

	treta.guardGate();
	std::cout << "\n";

	std::cout << "Time passes. Metal rusts.\n";
	treta.guardGate();
	tagarela.takeDamage(10);
	treta.takeDamage(10);
	std::cout << "\n";

	return (EXIT_SUCCESS);
}
