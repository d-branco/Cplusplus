/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   main.cpp                             :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/09/15 15:08:55      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/09/15 15:10:59     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>

#include "ClapTrap.hpp"

int main()
{
	ClapTrap tagarela("balabolka");
	ClapTrap treta("bladdermouth");

	std::cout << "\nNames: " << tagarela.get_name() << " and "
			  << treta.get_name() << "\n\n";

	tagarela.attack("bladdermouth");

	std::cout << "\n";

	treta.beRepaired(1);

	std::cout << "\n";

	return (EXIT_SUCCESS);
}
