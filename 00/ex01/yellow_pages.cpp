/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   yellow_pages.cpp                     :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/08/30 17:15:09      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/08/30 18:10:42     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include "yellow_pages.hpp"

void debug_write_signal(int signum);

int	 main()
{
	if (DEBUG)
	{
		std::cout << "DEBUG Starting\n";
	}

	signal(SIGINT, debug_write_signal);
	signal(SIGQUIT, debug_write_signal);

	PhoneBook	yellow_pages;
	std::string input;

	while (true) /////////////////////////////////////////////////////// loop //
	{
		std::cout << "Enter command: ADD, SEARCH or EXIT\n";
		if (!std::getline(std::cin, input) || (input == "EXIT"))
		{
			if (DEBUG)
			{
				if (input != "EXIT")
				{
					std::cout << "DEBUG EOF received\n";
				}
				std::cout << "DEBUG Exiting!\n";
			}
			break;
		}
		if (input == "ADD")
		{
			if (DEBUG)
			{
				std::cout << "DEBUG [ ] add_contact function.!\n";
			}
			yellow_pages.add_contact();
		}
		else if (input == "SEARCH")
		{
			if (DEBUG)
			{
				std::cout << "DEBUG [ ] search_contact function.!\n";
			}
			yellow_pages.search_contact();
		}
	}

	if (DEBUG)
	{
		std::cout << "DEBUG All's good!\n";
	}
	return (EXIT_SUCCESS);
}

void debug_write_signal(int signum)
{
	if (DEBUG)
	{
		if (signum == 2)
		{
			std::cerr << "\nDEBUG Signal: SIGINT (CTRL + C)\n";
		}
		else if (signum == 3)
		{
			std::cerr << "\nDEBUG Signal: SIGQUIT (CTRL + \\)\n";
		}
	}
}
