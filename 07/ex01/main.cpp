/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   main.cpp                             :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/11/25 14:42:58      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/11/25 16:36:22     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>

#include "iter.hpp"

int add_one(int ori);

int main(void)
{
	int array[3] = {1, 2, 3};

	std::cout << "Original array: " << array[0] << ", " << array[1] << ", "
			  << array[2] << "\n";
	iter(array, 3, add_one);
	std::cout << "Final array:    " << array[0] << ", " << array[1] << ", "
			  << array[2] << "\n";
	return (EXIT_SUCCESS);
}

int add_one(int ori)
{
	return (ori + 1);
}