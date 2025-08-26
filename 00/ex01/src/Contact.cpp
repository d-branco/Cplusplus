/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   Contact.cpp                          :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/08/25 11:53:28      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/08/26 21:26:06     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include "yellow_pages.hpp"

///////////////////////////////////////////////////////////////// Constructor //
Contact::Contact(std::string name,
				 std::string surname,
				 std::string nick,
				 int		 phone_number,
				 std::string secret) :
	name(name),
	surname(surname),
	nick(nick),
	phone_number(phone_number),
	secret(secret)
{
}

////////////////////////////////////////////////////////////////// Destructor //
Contact::~Contact()
{
}

//////////////////////////////////////////////////////////////////////// Copy //
Contact::Contact(const Contact &other) :
	name(other.name),
	surname(other.surname),
	nick(other.nick),
	phone_number(other.phone_number),
	secret(other.secret)
{
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
void Contact::set_name(const std::string &name)
{
	this->name = name;
}

void Contact::set_surname(const std::string &surname)
{
	this->surname = surname;
}

void Contact::set_nick(const std::string &nick)
{
	this->nick = nick;
}

void Contact::set_phone_number(int phone_number)
{
	this->phone_number = phone_number;
}

void Contact::set_secret(const std::string &secret)
{
	this->secret = secret;
}
