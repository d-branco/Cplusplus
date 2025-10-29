/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   main.cpp                             :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/10/28 16:58:56      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/10/29 09:49:32     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include <cstdlib>

#ifndef DEBUG
# define DEBUG false
#endif

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

	try
	{
		Bureaucrat fra("Jean Pierre", 42);
		std::cout << fra << "\n";
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << "\n";
	}
	return (EXIT_SUCCESS);
}
