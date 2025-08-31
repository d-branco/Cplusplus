/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   main.cpp                             :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/08/31 15:43:31      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/08/31 15:49:00     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name);

int		main()
{
	Zombie *ptr1 = zombieHorde(2, "Alice");
	Zombie *ptr2 = zombieHorde(2, "Bob");
	Zombie *ptr3 = zombieHorde(5, "Charlie");
	// ptr = zombieHorde(0, "Delta");
	// delete(ptr);
	delete[] ptr1;
	delete[] ptr2;
	delete[] ptr3;
}
