/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   main.cpp                             :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/10/28 16:58:56      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/11/22 11:07:55     #########  #########  ###      ###      */
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
	// try
	// {
	// 	Form zuv("Zweiundvierzig", false, 100, 20);
	// 	std::cout << zuv << "\n";

	// 	Form lov(zuv);
	// 	lov = zuv;
	// 	std::cout << "\n";

	// 	// Form qc0("Quelque", true, 150,151);
	// 	Form qc1("chose", true, 1, 0);
	// }
	// catch (const std::exception &e)
	// {
	// 	std::cout << e.what() << "\n";
	// }
	// std::cout << "\n";

	// try
	// {
	// 	Bureaucrat sus("Susana", 42);
	// 	Form	   zwei("Zwei", false, 40, 20);
	// 	std::cout << sus << "\n";
	// 	std::cout << zwei << "\n";

	// 	sus.signForm(zwei);
	// 	std::cout << zwei << "\n";
	// }
	// catch (const std::exception &e)
	// {
	// 	std::cout << e.what() << "\n";
	// }
	// std::cout << "\n";

	// try
	// {
	// 	Bureaucrat sus("Hannah", 42);
	// 	Form	   drei("Drei", false, 100, 20);
	// 	std::cout << sus << "\n";
	// 	std::cout << drei << "\n";

	// 	sus.signForm(drei);
	// 	std::cout << drei << "\n";
	// }
	// catch (const std::exception &e)
	// {
	// 	std::cout << e.what() << "\n";
	// }
	// std::cout << "\n";

	return (EXIT_SUCCESS);
}
