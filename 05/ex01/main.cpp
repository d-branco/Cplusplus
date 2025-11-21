/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   main.cpp                             :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/10/28 16:58:56      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/11/21 09:12:38     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#ifndef DEBUG
# define DEBUG false
#endif

#include <cstdlib>

#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat mil("Milhaes", 1000000);
		std::cout << mil << "\n";
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << "\n";
	}
	std::cout << "\n";

	try
	{
		Bureaucrat fra("Jean Pierre", 42);
		std::cout << fra << "\n";
		fra.grade_increment(40);
		fra.grade_increment(1);
		fra.grade_increment(1);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << "\n";
	}
	std::cout << "\n";

	try
	{
		Bureaucrat ger("Hans Miller", 127);
		std::cout << ger << "\n";
		ger.grade_decrement(1);
		ger.grade_decrement(1);
		ger.grade_decrement(40);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << "\n";
	}
	std::cout << "\n";

	try
	{
		Bureaucrat bri("Vicky Vitoria", 150);
		std::cout << bri << "\n";
		bri.grade_increment(100);
		bri.grade_decrement(1);
		bri.grade_increment(42);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << "\n";
	}
	// std::cout << "\n";

	return (EXIT_SUCCESS);
}
