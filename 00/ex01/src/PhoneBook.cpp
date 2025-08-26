/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   PhoneBook.cpp                        :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/08/26 21:02:44      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/08/26 21:46:24     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

///////////////////////////////////////////////////////////////// Constructor //
PhoneBook::Phonebook(int max_log) : max_log(max_log), current_log(0)
{
}
////////////////////////////////////////////////////////////////// Destructor //
PhoneBook::~Phonebook()
{
}
//////////////////////////////////////////////////////////////////////// Copy //
PhoneBook::PhoneBook(const PhoneBook &other) : max_log(other.max_log), current_log(other.current_log), line(other.line)
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
	//add_contact
	current_log++;
	if (current_log <= max_log)
	{
		current_log = 0;
	}
}
