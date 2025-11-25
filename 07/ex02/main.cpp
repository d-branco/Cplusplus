/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   main.cpp                             :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/11/25 18:46:44      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/11/25 20:53:53     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include "Array.hpp"

#include <cstdlib>
// #include <ctime>

#define MAX_VAL 750

int main(void)
{
	Array<int> alpha;
    std::cout << "Array of size: " << alpha.size() << "\n\n";

	// Array<int> numbers(MAX_VAL);
	// int		  *mirror = new int[MAX_VAL];
	// srand(time(NULL));
	// for (int i = 0; i < MAX_VAL; i++)
	// {
	// 	const int value = rand();
	// 	numbers[i]		= value;
	// 	mirror[i]		= value;
	// }
	// // SCOPE
	// {
	// 	Array<int> tmp = numbers;
	// 	Array<int> test(tmp);
	// }

	// for (int i = 0; i < MAX_VAL; i++)
	// {
	// 	if (mirror[i] != numbers[i])
	// 	{
	// 		std::cerr << "didn't save the same value!!" << std::endl;
	// 		return 1;
	// 	}
	// }
	// try
	// {
	// 	numbers[-2] = 0;
	// }
	// catch (const std::exception &e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
	// try
	// {
	// 	numbers[MAX_VAL] = 0;
	// }
	// catch (const std::exception &e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }

	// for (int i = 0; i < MAX_VAL; i++)
	// {
	// 	numbers[i] = rand();
	// }
	// delete[] mirror; //
	return (EXIT_SUCCESS);
}