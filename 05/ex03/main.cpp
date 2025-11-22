/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   main.cpp                             :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/10/28 16:58:56      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/11/22 14:40:18     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#ifndef DEBUG
# define DEBUG false
#endif

int main()
{
	try
	{
		Intern someRandomInter;
		AForm *rrf;

		rrf = someRandomInter.makeForm("robotomy request", "Bender");
		std::cout << *rrf << "\n";
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << "\n";
	}
	std::cout << "\n";

	try
	{
		Intern someRandomInter;
		AForm *rrf;

		rrf = someRandomInter.makeForm("clear skies", "Porto");
		std::cout << *rrf << "\n";
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << "\n";
	}
	// std::cout << "\n";

	return (EXIT_SUCCESS);
}
