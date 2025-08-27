/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   PhoneBook.cpp                        :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/08/28 19:20:32      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/08/28 20:18:36     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include "PhoneBook.hpp"

///////////////////////////////////////////////////////////////// Constructor //
PhoneBook::PhoneBook() : current_log(0)
{
	if (DEBUG)
	{
		std::cout << "DEBUG PhoneBook constructed.\n";
	}
}

////////////////////////////////////////////////////////////////// Destructor //
PhoneBook::~PhoneBook()
{
	if (DEBUG)
	{
		std::cout << "DEBUG PhoneBook desstructed.\n";
	}
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
//	if (index >= MAX_LOG)
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

	if (current_log >= MAX_LOG)
	{
		current_log = 0;
	}
}

/////////////////////////////////////////////////////////// Add a new contact //
void PhoneBook::search_contact(const Contact &person)
{
	(void) person;
}
