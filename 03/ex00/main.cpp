/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   main.cpp                             :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/09/15 11:12:25      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/09/15 11:17:21     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>

#include "ClapTrap.hpp"

int main()
{
	ClapTrap tagarela("balabolka");
	ClapTrap treta("bladdermouth");

	std::cout << "Names: " << tagarela.get_name() << " and " << treta.get_name()
			  << "\n";

	ClapTrap terceiro(treta);

	std::cout << "Names: " << terceiro.get_name() << " and " << treta.get_name()
			  << "\n";

	return (EXIT_SUCCESS);
}
