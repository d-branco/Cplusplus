/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   PhoneBook.cpp                        :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/08/30 18:09:12      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/08/30 19:00:31     #########  #########  ###      ###      */
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
PhoneBook::PhoneBook(const PhoneBook &other) : current_log_(other.current_log_)
{
}

PhoneBook &PhoneBook::operator=(const PhoneBook &other)
{
	if (this != &other)
	{
		current_log_ = other.current_log_;
	}
	return (*this);
}

///////////////////////////////////////////////////////////////////// Getters //
///////////////////////////////////////////////////////////////////// Setters //
/////////////////////////////////////////////////////////// Add a new contact //
void PhoneBook::add_contact()
{
	if (DEBUG)
	{
		std::cout << "DEBUG PhoneBook: adding contact. Current log: "
				  << current_log_ << "\n";
	}

	line_[current_log_].set_name(get_string("Enter contact first name:\n"));
	line_[current_log_].set_surname(get_string("Enter contact last name:\n"));
	line_[current_log_].set_nick(get_string("Enter contact nickname:\n"));

	size_t		input_length = 0;
	std::string input;
	while (input_length == 0)
	{
		std::cout << "Enter contact number:\n";
		if (!std::getline(std::cin, input))
		{
			exit(EXIT_FAILURE);
		}
		input_length = input.length();
		size_t chr	 = 0;
		while (chr < input_length)
		{
			if (isdigit(input[chr]) == 0)
			{
				input_length = 0;
				break;
			}
			chr++;
		}
	}
	line_[current_log_].set_phone_number(input);

	line_[current_log_].set_secret(
		get_string("Enter contact darkest secret:\n"));

	current_log_++;
	if (current_log_ >= MAX_LOG)
	{
		current_log_ = 0;
	}
}

std::string PhoneBook::get_string(const std::string &str) const
{
	std::string input;
	size_t		input_length = 0;

	while (input_length == 0)
	{
		std::cout << str;
		if (!std::getline(std::cin, input))
		{
			exit(EXIT_FAILURE);
		}
		input_length = input.length();
		size_t chr	 = 0;
		while (isspace(input[chr]) != 0)
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

////////////////////////////////////////////////////////////// Search contact //
void PhoneBook::search_contact()
{
	if (DEBUG)
	{
		std::cout << "DEBUG PhoneBook: search_contat: displaying table.\n";
	}
	size_t nbr = 0;
	while (nbr < MAX_LOG)
	{
		if (line_[nbr].get_name().empty())
		{
			nbr++;
			continue;
		}
		std::cout << std::setw(3) << nbr;
		print_padded(line_[nbr].get_name());
		print_padded(line_[nbr].get_surname());
		print_padded(line_[nbr].get_nick());
		std::cout << "\n";
		nbr++;
	}

	if (DEBUG)
	{
		std::cout << "DEBUG PhoneBook: search_contat: searching index.\n";
	}
	std::string input;
	std::cout << "Enter index to display: \n";
	if (!std::getline(std::cin, input))
	{
		exit(EXIT_FAILURE);
	}
	if ((input.length() == 1) && (isdigit(input[0]) != 0) &&
		((input[0] - '0') < MAX_LOG) &&
		(!line_[(input[0] - '0')].get_name().empty()))
	{
		nbr = input[0] - '0';
		std::cout << "      First name: " << line_[nbr].get_name() << "\n";
		std::cout << "       Last name: " << line_[nbr].get_surname() << "\n";
		std::cout << "        Nickname: " << line_[nbr].get_nick() << "\n";
		std::cout << "    Phone number: " << line_[nbr].get_phone_number()
				  << "\n";
		std::cout << "  Darkest secret: " << line_[nbr].get_secret() << "\n";
	}
	else
	{
		std::cerr << "Invalid index\n";
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
