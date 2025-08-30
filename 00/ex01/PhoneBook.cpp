/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   PhoneBook.cpp                        :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/08/30 15:40:35      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/08/30 16:52:56     #########  #########  ###      ###      */
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
	std::string input = get_string("Contact first name:\n");
	line_[current_log_].set_name(input);
	input = get_string("Contact last name:\n");
	line_[current_log_].set_surname(input);
	input = get_string("Contact nickname:\n");
	line_[current_log_].set_nick(input);
	// input = get_string("Contact NAME:\n");
	//	line_[current_log_].set_name(input);
	input = get_string("Contact darkest secret:\n");
	line_[current_log_].set_secret(input);

	current_log_++;
	if (current_log_ >= MAX_LOG)
	{
		current_log_ = 0;
	}
}

std::string PhoneBook::get_string(const std::string &str) const
{
	std::string input		 = "";
	size_t		input_length = 0;

	while (input_length == 0)
	{
		std::cout << str;
		std::getline(std::cin, input);
		input_length = input.length();
		size_t chr	 = 0;
		while (isspace(input[chr]))
		{
			chr++;
			if (chr == input_length)
			{
				input_length = 0;
				break;
			}
		}
	}
	return (input);
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
			continue;
		}
		std::cout << std::setw(3) << i;
		print_padded(line_[i].get_name());
		print_padded(line_[i].get_surname());
		print_padded(line_[i].get_nick());
		std::cout << "\n";
		i++;
	}

	if (DEBUG)
	{
		std::cout << "DEBUG PhoneBook: search_contat: searching index.\n";
	}
}

void PhoneBook::print_padded(const std::string &str) const
{
	std::string temp;

	std::cout << " | ";
	if (str.length() > COLUMN_WIDTH)
	{
		temp = str.substr(0, COLUMN_WIDTH - 1);
		temp = temp + ".";
		std::cout << temp;
	}
	else
	{
		std::cout << std::setw(COLUMN_WIDTH) << str;
	}
}
