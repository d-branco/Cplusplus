/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   yellow_pages.cpp                     :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/08/28 19:19:00      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/08/28 20:34:47     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include "yellow_pages.hpp"

int main()
{
	if (DEBUG)
	{
		std::cout << "DEBUG Starting\n";
	}

	if (DEBUG)
	{
		std::cout << "DEBUG all the way!\n";
	}

	PhoneBook yellow_pages;

	Contact	  new_contact1(
		  "Joao", "Chaves", "Pacific", 912345678, "Loves to be called Johnny");

	Contact new_contact2 = new_contact1;
	// yellow_pages.add_contact(new_contact2);
	// std::cout << "Second contact added\n";

	new_contact1.set_name("Isabel");
	new_contact1.set_surname("Bella");
	new_contact1.set_nick("Stillwell");
	new_contact1.set_phone_number(924680135);
	new_contact1.set_secret("Adores mint chocolate");
	if (DEBUG)
	{
		std::cout << "DEBUG First contact edited\n";
	}

	// yellow_pages.add_contact(new_contact1);
	// std::cout << "First contact added\n";

	if (DEBUG)
	{
		std::cout << "DEBUG " << new_contact1.get_name() << " \""
				  << new_contact1.get_nick() << "\" "
				  << new_contact1.get_surname() << "\n";
	}

	if (DEBUG)
	{
		std::cout << "DEBUG " << new_contact2.get_name() << " \""
				  << new_contact2.get_nick() << "\" "
				  << new_contact2.get_surname() << "\n";
	}

	if (DEBUG)
	{
		std::cout << "DEBUG All's good!\n";
	}
	std::cout << "\n[ ] Copy and copy operator overload on PhoneBook\n\n";
	return (EXIT_SUCCESS);
}
