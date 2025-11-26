/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   easyfind.hpp                         :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/11/26 15:46:09      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/11/26 17:48:44     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#ifndef DEBUG
# define DEBUG false
#endif

#include <algorithm>
#include <iostream>

template <typename T>
typename T::const_iterator easyfind(const T &int_container, int nbr)
{
	if (DEBUG)
	{
		std::cout << "==DEBUG== Easyfind()\n";
	}
	typename T::const_iterator pos = int_container.begin();
	typename T::const_iterator end = int_container.end();
	try
	{
		for (;;)
		{
			if (*pos == nbr)
			{
				std::cout << "INT " << *pos << " found\n";
				return (pos);
			}

			if (pos == end)
			{
				throw std::exception();
				std::cout << "TESTE\n ";
			}
			pos++;
		}
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: INT " << nbr << " not found\n";
	}

	return (end);
};

#endif
