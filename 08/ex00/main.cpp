/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   main.cpp                             :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/11/26 15:46:09      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/11/26 17:45:55     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include <algorithm>
#include <cstdlib>
#include <vector>

#include "easyfind.hpp"

int main(void)
{
	std::vector<int> array;
	std::cout << "array:\n";
	int i = 1;
	for (;;)
	{
		array.push_back(i);
		std::cout << i;
		i *= 2;
		if (i > 225)
		{
			std::cout << "\n";
			break;
		}
		std::cout << ", ";
	}
	std::cout << "\nSearching for int: 16\n";
	std::vector<int>::const_iterator pos = easyfind(array, 16);
	std::cout << "\nSearching for int: 42\n";
	pos = easyfind(array, 42);

	return (EXIT_SUCCESS);
}
