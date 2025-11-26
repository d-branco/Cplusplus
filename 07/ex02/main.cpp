/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   main.cpp                             :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/11/25 18:46:44      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/11/26 08:21:57     #########  #########  ###      ###      */
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

	int *a = new int();
	std::cout << "Array 'a' (at adress: " << a << "):\n" << *a << "\n";

	unsigned int tttf = 16;
	int			*b	  = new int[tttf];
	std::cout << "Array 'b' (at adress: " << b << "):\n";
	// Coment this "for loop" for an array set to zeroes! And some memory errors
	for (unsigned int ite = 0; ite < tttf; ite++)
	{
		b[ite] = ite - 42;
	}
	for (unsigned int ite = 0; ite < tttf - 1; ite++)
	{
		std::cout << b[ite] << ", ";
	}
	std::cout << b[tttf - 1] << "\n\n";
	delete (a);
	delete[] (b);

	Array<int> delta(tttf);
	for (unsigned int ite = 0; ite < tttf; ite++)
	{
		delta[ite] = ite - 42;
	}
	std::cout << "Array 'delta' (at adress: " << &delta << "):\n";
	for (unsigned int ite = 0; ite < tttf - 1; ite++)
	{
		std::cout << delta[ite] << ", ";
	}
	std::cout << delta[tttf - 1] << "\n";
	Array<int> test_copy(delta);
	std::cout << "Array 'test_copy' (at adress: " << &test_copy << "):\n";
	for (unsigned int ite = 0; ite < tttf - 1; ite++)
	{
		std::cout << test_copy[ite] << ", ";
	}
	std::cout << test_copy[tttf - 1] << "\n";
	Array<int> test_copy_operator = delta;
	std::cout << "Array 'test_copy_operator' (at adress: "
			  << &test_copy_operator << "):\n";
	for (unsigned int ite = 0; ite < tttf - 1; ite++)
	{
		std::cout << test_copy_operator[ite] << ", ";
	}
	std::cout << test_copy_operator[tttf - 1] << "\n\n";
	Array<int> test_out_of_bounds(delta);
	std::cout << "Array 'test_out_of_bounds' (at adress: "
			  << &test_out_of_bounds << "):\n";
	for (unsigned int ite = 0; ite < tttf - 1; ite++)
	{
		std::cout << test_out_of_bounds[ite] << ", ";
	}
	std::cout << test_out_of_bounds[tttf - 1] << "\n";
	try
	{
		std::cout << test_out_of_bounds[tttf] << "\n";
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception caught: out of bounds: " << e.what() << '\n';
	}

	return (EXIT_SUCCESS);
}