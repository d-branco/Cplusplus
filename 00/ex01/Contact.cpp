/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   Contact.cpp                          :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/08/28 18:36:23      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/08/28 19:02:35     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include "Contact.hpp"

///////////////////////////////////////////////////////////////// Constructor //
Contact::Contact()
{
	if (DEBUG)
		std::cout << "DEBUG Contact created with default constructor.\n";
}

Contact::Contact(const std::string &name,
	const std::string			   &surname,
	const std::string			   &nick,
	int								phone_number,
	const std::string			   &secret) :
	name(name),
	surname(surname),
	nick(nick),
	phone_number(phone_number),
	secret(secret)
{
	if (DEBUG)
		std::cout << "DEBUG Contact created with parameterized constructor.\n";
}

////////////////////////////////////////////////////////////////// Destructor //
Contact::~Contact()
{
	if (DEBUG)
		std::cout << "DEBUG Contact destructed.\n";
}

//////////////////////////////////////////////////////////////////////// Copy //
Contact::Contact(const Contact &other) :
	name(other.name),
	surname(other.surname),
	nick(other.nick),
	phone_number(other.phone_number),
	secret(other.secret)
{
	if (DEBUG)
		std::cout << "DEBUG Contact created with copy constructor.\n";
}

Contact &Contact::operator=(const Contact &other)
{
	if (this != &other)
	{
		name = other.name;
		surname = other.surname;
		nick = other.nick;
		phone_number = other.phone_number;
		secret = other.secret;
	}
	return *this;
}

///////////////////////////////////////////////////////////////////// Getters //
std::string Contact::get_name() const
{
	return name;
}

std::string Contact::get_surname() const
{
	return surname;
}

std::string Contact::get_nick() const
{
	return nick;
}

int Contact::get_phone_number() const
{
	return phone_number;
}

std::string Contact::get_secret() const
{
	return secret;
}

///////////////////////////////////////////////////////////////////// Setters //
void Contact::set_name(const std::string &new_name)
{
	this->name = new_name;
}

void Contact::set_surname(const std::string &new_surname)
{
	this->surname = new_surname;
}

void Contact::set_nick(const std::string &new_nick)
{
	this->nick = new_nick;
}

void Contact::set_phone_number(int new_phone_number)
{
	this->phone_number = new_phone_number;
}

void Contact::set_secret(const std::string &new_secret)
{
	this->secret = new_secret;
}
