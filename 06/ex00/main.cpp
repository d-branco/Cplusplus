/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   main.cpp                             :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/11/23 10:56:12      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/11/24 17:54:28     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc > 2)
	{
		std::cout << "Error:\n  Too many argument!\n";

		return (EXIT_SUCCESS);
	}
	if (argc == 2)
	{
		ScalarConverter::convert(argv[1]);

		return (EXIT_SUCCESS);
	}
	ScalarConverter::convert("0");
	std::cout << "\n";
	ScalarConverter::convert("nan");
	std::cout << "\n";
	ScalarConverter::convert("42.0f");
	std::cout << "\n";

	ScalarConverter::convert("*");
	std::cout << "\n";
	ScalarConverter::convert("\t");
	std::cout << "\n";

	ScalarConverter::convert("inf");
	std::cout << "\n";
	ScalarConverter::convert("+inff");
	std::cout << "\n";
	ScalarConverter::convert("-inf");
	std::cout << "\n";
	ScalarConverter::convert("+0");
	std::cout << "\n";
	ScalarConverter::convert("-2");
	std::cout << "\n";
	ScalarConverter::convert("+225");

	std::cout << "\n";
	ScalarConverter::convert("43.225");
	std::cout << "\n";
	ScalarConverter::convert("9.225");
	std::cout << "\n";
	ScalarConverter::convert("-9.225");

	return (EXIT_SUCCESS);
}
