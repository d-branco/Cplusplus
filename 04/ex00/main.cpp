/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   main.cpp                             :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/09/16 11:21:30      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/09/16 11:45:20     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

// Remember to make "the most complete tests"!

#include "Animal.hpp"

#include <cstdlib>

int main()
{
	Animal chimera("chimera");
	Animal hydra(chimera);

	return (EXIT_SUCCESS);
}
