/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   PhoneBook.cpp                        :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/08/28 21:40:58      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/08/30 11:21:06     #########  #########  ###      ###      */
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
//	line(other.line)
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
//	return (line[index]);
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
	line[current_log_].set_name(input);
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
		std::cout << "DEBUG PhoneBook: searching contact.\n";
	}
}
