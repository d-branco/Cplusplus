/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   main.cpp                             :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/10/28 16:58:56      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/10/29 09:02:43     #########  #########  ###      ###      */
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
	}
	catch (const std::exception &glitching_glitch)
	{
		std::cout << glitching_glitch.what() << "\n";
	}
	return (EXIT_SUCCESS);
}
