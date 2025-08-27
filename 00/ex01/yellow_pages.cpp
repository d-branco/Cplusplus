/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   yellow_pages.cpp                     :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/08/28 18:37:01      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/08/28 18:37:23     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include "yellow_pages.hpp"

int main()
{
	std::cout << "Starting\n";

	if (DEBUG)
		std::cout << "There's DEBUG\n";
	else
		std::cout << "There's NO debug\n";

	PhoneBook ph_book;
	std::cout << "PhoneBook created\n";

	Contact new_contact1("Joao",
		"Ferreira",
		"John",
		912345678,
		"Prefers to be called Johnny by his friends");
	std::cout << "First contact created\n";

	Contact new_contact2 = new_contact1;
	std::cout << "Second contact created by copying the first\n";
	// ph_book.add_contact(new_contact2);
	// std::cout << "Second contact added\n";

	new_contact1.set_name("Hannah");
	new_contact1.set_surname("Keys");
	new_contact1.set_nick("Chaves");
	new_contact1.set_phone_number(924680135);
	new_contact1.set_secret("Likes mint chocolate");
	std::cout << "First contact edited\n";

	// ph_book.add_contact(new_contact1);
	// std::cout << "First contact added\n";

	std::cout << new_contact1.get_name() << " \"" << new_contact1.get_nick()
			  << "\" " << new_contact1.get_surname() << "\n";

	std::cout << new_contact2.get_name() << " \"" << new_contact2.get_nick()
			  << "\" " << new_contact2.get_surname() << "\n";

	std::cout << "All's good!\n";
	return (EXIT_SUCCESS);
}
