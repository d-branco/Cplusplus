/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   PhoneBook.cpp                        :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/08/28 09:22:59      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/08/28 09:28:00     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include "yellow_pages.hpp"

///////////////////////////////////////////////////////////////// Constructor //
PhoneBook::PhoneBook(int max_log) : max_log(max_log), current_log(0)
{
	if (max_log <= 0)
		max_log = 1;
}

////////////////////////////////////////////////////////////////// Destructor //
PhoneBook::~PhoneBook()
{
}

//////////////////////////////////////////////////////////////////////// Copy //
PhoneBook::PhoneBook(const PhoneBook &other) :
	max_log(other.max_log),
	current_log(other.current_log),
	line(other.line)
{
}

PhoneBook &PhoneBook::operator=(const PhoneBook &other)
{
	if (this != &other)
	{
		current_log = other.current_log;
		line = other.line;
	}
	return (*this);
}

///////////////////////////////////////////////////////////////////// Getters //
const Contact &PhoneBook::get_line(int index) const
{
	if (index >= max_log)
	{
		index = 0;
	}
	return (line[index]);
}

///////////////////////////////////////////////////////////////////// Setters //
/////////////////////////////////////////////////////////// Add a new contact //
void PhoneBook::add_contact(const Contact &new_contact)
{
	line[current_log] = new_contact;

	if (current_log >= max_log)
		current_log = 0;
}
