/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   main.cpp                             :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/11/25 14:42:58      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/11/25 16:57:12     #########  #########  ###      ###      */
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
			  << array[2] << "\n";

	char arr[5] = {'C', 'E', 'S', 'A', 'R'};
	std::cout << "Original array: " << arr[0] << ", " << arr[1] << ", "
			  << arr[2] << ", " << arr[3] << ", " << arr[4] << "\n";

	iter(arr, 3, add_one);
	std::cout << "Final array:    " << arr[0] << ", " << arr[1] << ", "
			  << arr[2] << ", " << arr[3] << ", " << arr[4] << "\n";
	return (EXIT_SUCCESS);
}
