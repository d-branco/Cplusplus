/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   main.cpp                             :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/11/23 10:56:12      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/11/23 12:05:15     #########  #########  ###      ###      */
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
	return (EXIT_SUCCESS);
}
