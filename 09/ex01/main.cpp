/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   main.cpp                             :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/12/02 20:26:16      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/12/21 12:25:14     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include "RPN.hpp"
#include <cstdlib>
#include <iostream>

// stack: adapts a container to provide stack (LIFO data structure)
int main(int argc, char **argv)
{
	dprint("Debug mode activated");
	if (argc != 2)
	{
		dprint("argc: " << argc);
		std::cerr << "Error\n";
		return (EXIT_FAILURE);
	}
	dprint("");

	RPN polish;
	return (polish.run(argv[1]));
}
