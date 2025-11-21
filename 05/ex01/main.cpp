/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   main.cpp                             :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/10/28 16:58:56      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/11/21 11:07:25     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include <cstdlib>

#include "Bureaucrat.hpp"
#include "Form.hpp"

#ifndef DEBUG
# define DEBUG false
#endif

int main()
{
	try
	{
		Form zuv("Zweiundvierzig", false, 100, 20);
		std::cout << zuv << "\n";

		// Form lov(zuv);
		// lov = zuv;
		// std::cout << "\n";
		
		// //Form qc0("Quelque", true, 150,151);
		//Form qc1("chose", true, 1,0);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << "\n";
	}
	// std::cout << "\n";

	return (EXIT_SUCCESS);
}
