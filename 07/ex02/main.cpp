/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   main.cpp                             :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/11/25 18:46:44      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/11/25 21:22:43     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include "Array.hpp"

#include <cstdlib>

// #include <ctime>

// #define MAX_VAL 750

int main(void)
{
	Array<int> alpha;
	std::cout << "Array of size: " << alpha.size() << "\n";
	Array<int> bravo(0);
	std::cout << "Array of size: " << bravo.size() << "\n";
	Array<int> charlie(42);
	std::cout << "Array of size: " << charlie.size() << "\n\n";

	unsigned int ft = 16;
	int * a = new int[ft];
	std::cout << "Array 'a' (at adress: " << a << "):\n";
	for (unsigned int ite = 0; ite < ft; ite++)
	{
		a[ite] = ite -42;
	}
	for (unsigned int ite = 0; ite < ft - 1; ite++)
	{
		std::cout << a[ite] << ", ";
	}
	std::cout << a[ft - 1] << "\n\n";
	delete[] (a);

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