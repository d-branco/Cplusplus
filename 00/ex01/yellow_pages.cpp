/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   yellow_pages.cpp                     :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/08/30 13:53:21      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/08/30 14:02:19     #########  #########  ###      ###      */
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

	/*if (DEBUG)
	{
		Contact new_contact1("Joao",
							 "Chaves",
							 "Pacific",
							 912345678,
							 "Loves to be called Johnny");

		Contact new_contact2 = new_contact1;
		// yellow_pages.add_contact(new_contact2);
		// std::cout << "Second contact added\n";

		new_contact1.set_name("Bianca");
		new_contact1.set_surname("Vasel");
		new_contact1.set_nick("The Voice");
		new_contact1.set_phone_number(924680135);
		new_contact1.set_secret("Adores mint chocolate");
		std::cout << "DEBUG First contact edited\n";

		// yellow_pages.add_contact(new_contact1);
		// std::cout << "First contact added\n";

		std::cout << "DEBUG " << new_contact1.get_name() << " \""
				  << new_contact1.get_nick() << "\" "
				  << new_contact1.get_surname() << "\n";

		std::cout << "DEBUG " << new_contact2.get_name() << " \""
				  << new_contact2.get_nick() << "\" "
				  << new_contact2.get_surname() << "\n";
	}*/

	while (true) /////////////////////////////////////////////////////// loop //
	{
		std::cout << "(ADD), (SEARCH), EXIT\n";
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
	std::cout << "\n - [ ] ADD contact function.!\n";
	std::cout << " - [ ] SEARCH contact function.!\n";
	std::cout << " - [ ] Set MAX_LOG = 3\n";
	std::cout << " - [ ] Copy and copy operator overload"
			  << " on PhoneBook class\n\n";
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
	// exit(EXIT_FAILURE);
}
