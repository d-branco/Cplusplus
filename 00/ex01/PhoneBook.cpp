/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   PhoneBook.cpp                        :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/08/28 18:36:23      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/08/28 18:43:11     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include "PhoneBook.hpp"

///////////////////////////////////////////////////////////////// Constructor //
PhoneBook::PhoneBook()
{
	current_log = 0;
	if (DEBUG)
		std::cout << "DEBUG PhoneBook constructed.\n";
}

////////////////////////////////////////////////////////////////// Destructor //
PhoneBook::~PhoneBook()
{
	if (DEBUG)
		std::cout << "DEBUG PhoneBook desstructed.\n";
}

//////////////////////////////////////////////////////////////////////// Copy //
// PhoneBook::PhoneBook(const PhoneBook &other) :
//	current_log(other.current_log),
//	line(other.line)
//{
// }
//
// PhoneBook &PhoneBook::operator=(const PhoneBook &other)
//{
//	if (this != &other)
//	{
//		current_log = 0;
//	}
//	return (*this);
// }
//
///////////////////////////////////////////////////////////////////// Getters //
// const Contact &PhoneBook::get_line(int index) const
//{
//	if (index >= 8)
//	{
//		index = 0;
//	}
//	return (line[index]);
// }
//
///////////////////////////////////////////////////////////////////// Setters //
/////////////////////////////////////////////////////////// Add a new contact //
void PhoneBook::add_contact(const Contact &person)
{
	(void) person;
	// line[current_log] = person;

	if (current_log >= 8)
		current_log = 0;
}

/////////////////////////////////////////////////////////// Add a new contact //
void PhoneBook::search_contact(const Contact &person)
{
	(void) person;
}
