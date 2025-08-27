/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   Contact.cpp                          :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/08/28 21:33:05      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/08/28 21:41:29     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include "Contact.hpp"
#include "yellow_pages.hpp"

///////////////////////////////////////////////////////////////// Constructor //
Contact::Contact()
{
	if (DEBUG)
		std::cout << "DEBUG Contact created with default constructor.\n";
}

Contact::Contact(const std::string &name,
				 const std::string &surname,
				 const std::string &nick,
				 int				phone_number,
				 const std::string &secret) :
	name_(name),
	surname_(surname),
	nick_(nick),
	phone_number_(phone_number),
	secret_(secret)
{
	if (DEBUG)
	{
		std::cout << "DEBUG Contact created with parameterized constructor.\n";
	}
}

////////////////////////////////////////////////////////////////// Destructor //
Contact::~Contact()
{
	if (DEBUG)
	{
		std::cout << "DEBUG Contact destructed.\n";
	}
}

//////////////////////////////////////////////////////////////////////// Copy //
Contact::Contact(const Contact &other) :
	name_(other.name_),
	surname_(other.surname_),
	nick_(other.nick_),
	phone_number_(other.phone_number_),
	secret_(other.secret_)
{
	if (DEBUG)
	{
		std::cout << "DEBUG Contact created with copy constructor.\n";
	}
}

Contact &Contact::operator=(const Contact &other)
{
	if (this != &other)
	{
		name_		  = other.name_;
		surname_	  = other.surname_;
		nick_		  = other.nick_;
		phone_number_ = other.phone_number_;
		secret_		  = other.secret_;
	}
	return *this;
}

///////////////////////////////////////////////////////////////////// Getters //
std::string Contact::get_name() const
{
	return name_;
}

std::string Contact::get_surname() const
{
	return surname_;
}

std::string Contact::get_nick() const
{
	return nick_;
}

int Contact::get_phone_number() const
{
	return phone_number_;
}

std::string Contact::get_secret() const
{
	return secret_;
}

///////////////////////////////////////////////////////////////////// Setters //
void Contact::set_name(const std::string &new_name)
{
	this->name_ = new_name;
}

void Contact::set_surname(const std::string &new_surname)
{
	this->surname_ = new_surname;
}

void Contact::set_nick(const std::string &new_nick)
{
	this->nick_ = new_nick;
}

void Contact::set_phone_number(int new_phone_number)
{
	this->phone_number_ = new_phone_number;
}

void Contact::set_secret(const std::string &new_secret)
{
	this->secret_ = new_secret;
}
