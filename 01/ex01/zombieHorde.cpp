/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   zombieHorde.cpp                      :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/08/31 15:43:31      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/08/31 15:52:28     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
	if (N <= 0)
	{
		return (NULL);
	}

	Zombie *horde = new Zombie[N];
	int		i	  = 0;
	while (i < N)
	{
		horde[i].set_name(name);
		horde[i].announce();
		i++;
	}

	return (horde);
}
