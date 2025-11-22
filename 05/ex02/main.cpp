/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   main.cpp                             :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/10/28 16:58:56      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/11/22 13:04:27     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include <cstdlib>

#include "AForm.hpp"
#include "Bureaucrat.hpp"
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
		Bureaucrat			   sus("Susana", 42);
		PresidentialPardonForm fire("Artur");
		std::cout << sus << "\n";
		std::cout << fire << "\n";

		sus.signForm(fire);
		std::cout << fire << "\n";

		fire.execute(sus);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << "\n";
	}
	std::cout << "\n";

	try
	{
		Bureaucrat			   sus("Susana", 25);
		PresidentialPardonForm fire("Artur");
		std::cout << sus << "\n";
		std::cout << fire << "\n";

		sus.signForm(fire);
		std::cout << fire << "\n";

		fire.execute(sus);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << "\n";
	}
	std::cout << "\n";

	try
	{
		Bureaucrat			   sus("Susana", 4);
		PresidentialPardonForm fire("Artur");
		std::cout << sus << "\n";
		std::cout << fire << "\n";

		sus.signForm(fire);
		std::cout << fire << "\n";

		fire.execute(sus);
		sus.executeForm(fire);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << "\n";
	}
	std::cout << "\n\n";

	std::srand(std::time(0));
	try
	{
		Bureaucrat			sus("Susana", 77);
		RobotomyRequestForm needle("Marvin");
		std::cout << sus << "\n";
		std::cout << needle << "\n";

		sus.signForm(needle);
		std::cout << needle << "\n";

		needle.execute(sus);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << "\n";
	}
	std::cout << "\n";

	try
	{
		Bureaucrat			sus("Susana", 55);
		RobotomyRequestForm needle("Marvin");
		std::cout << sus << "\n";
		std::cout << needle << "\n";

		sus.signForm(needle);
		std::cout << needle << "\n";

		needle.execute(sus);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << "\n";
	}
	std::cout << "\n";

	try
	{
		Bureaucrat			sus("Susana", 44);
		RobotomyRequestForm needle("Marvin");
		std::cout << sus << "\n";
		std::cout << needle << "\n";

		sus.signForm(needle);
		std::cout << needle << "\n";

		needle.execute(sus);
		needle.execute(sus);
		needle.execute(sus);
		needle.execute(sus);
		needle.execute(sus);
		needle.execute(sus);
		needle.execute(sus);
		needle.execute(sus);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << "\n";
	}
	std::cout << "\n\n";

	return (EXIT_SUCCESS);
}
