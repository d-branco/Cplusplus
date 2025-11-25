/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   main.cpp                             :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/11/25 14:42:58      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/11/25 18:38:42     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>

#include "iter.hpp"

int main(void)
{
	int array[3] = {1, 2, 3};
	std::cout << "Original array: " << array[0] << ", " << array[1] << ", "
			  << array[2] << "\n";
	iter(array, 3, add_one);
	std::cout << "Final array:    " << array[0] << ", " << array[1] << ", "
			  << array[2] << "\n\n";

	char arr[5] = {'C', 'E', 'S', 'A', 'R'};
	std::cout << "Original array: " << arr[0] << ", " << arr[1] << ", "
			  << arr[2] << ", " << arr[3] << ", " << arr[4] << "\n";
	iter(arr, 5, add_one);
	iter(arr, 5, add_one);
	std::cout << "Final array:    " << arr[0] << ", " << arr[1] << ", "
			  << arr[2] << ", " << arr[3] << ", " << arr[4] << "\n\n";

	const int ecole[2] = {4, 2};
	std::cout << "Original array: " << ecole[0] << ", " << ecole[1] << "\n";
	iter(ecole, 2, print_the_next);
	std::cout << "Final array:    " << ecole[0] << ", " << ecole[1] << "\n";
	return (EXIT_SUCCESS);
}
