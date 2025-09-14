/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   main.cpp                             :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/08/31 15:43:31      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/08/31 16:09:11     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name);

int		main()
{
	Zombie *ptr1 = zombieHorde(2, "Alice");
	for (int i = 0; i < 2; i++)
	{
		ptr1[i].announce();
	}
	Zombie *ptr2 = zombieHorde(2, "Bob");
	for (int i = 0; i < 2; i++)
	{
		ptr2[i].announce();
	}
	Zombie *ptr3 = zombieHorde(5, "Charlie");
	for (int i = 0; i < 5; i++)
	{
		ptr3[i].announce();
	}
	Zombie *ptr4 = zombieHorde(0, "Delta");
	for (int i = 0; i < 0; i++)
	{
		ptr4[i].announce();
	}
	delete[] ptr1;
	delete[] ptr2;
	delete[] ptr3;
	delete[] ptr4;
}
