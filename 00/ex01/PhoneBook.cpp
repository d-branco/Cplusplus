/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   PhoneBook.cpp                        :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/08/30 13:53:21      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/08/30 14:03:04     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "yellow_pages.hpp"

///////////////////////////////////////////////////////////////// Constructor //
PhoneBook::PhoneBook() : current_log_(0)
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
		std::cout << "DEBUG PhoneBook destructed.\n";
	}
}

//////////////////////////////////////////////////////////////////////// Copy //
// PhoneBook::PhoneBook(const PhoneBook &other) :
//	current_log_(other.current_log_),
//	line_(other.line_)
//{
// }
//
// PhoneBook &PhoneBook::operator=(const PhoneBook &other)
//{
//	if (this != &other)
//	{
//		current_log_ = 0;
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
//	return (line_[index]);
// }
//
///////////////////////////////////////////////////////////////////// Setters //
/////////////////////////////////////////////////////////// Add a new contact //
void PhoneBook::add_contact()
{
	if (DEBUG)
	{
		std::cout << "DEBUG PhoneBook: adding contact. Current log: "
				  << current_log_ << "\n";
	}
	std::string input;
	std::cout << "Contact NAME:\n";
	std::getline(std::cin, input);
	line_[current_log_].set_name(input);
	current_log_++;
	if (current_log_ >= MAX_LOG)
	{
		current_log_ = 0;
	}
}

/////////////////////////////////////////////////////////// Add a new contact //
void PhoneBook::search_contact()
{
	if (DEBUG)
	{
		std::cout << "DEBUG PhoneBook: search_contat: displaying table.\n";
	}
	int i = 0;
	while (i < MAX_LOG)
	{
		if (line_[i].get_name().length() == 0)
		{
			i++;
			continue ;
		}
		std::cout << std::setw(3) << i << " | ";
		print_padded(line_[i].get_name());
		i++;
	}

	if (DEBUG)
	{
		std::cout << "DEBUG PhoneBook: search_contat: searching index.\n";
	}
}

void	PhoneBook::print_padded(const std::string &str) const
{
	std::string temp = "";
	if (str.length() > 10)
	{
		temp = str.substr(0, 9);
		temp = temp + ".";
		std::cout << temp << " | ";
	}
	else
	{
		std::cout << std::setw(10) << str;
		std::cout << " | ";
	}
	std::cout << "\n";
}
