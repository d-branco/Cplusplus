/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   Harl.cpp                             :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/09/01 12:50:21      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/09/01 12:50:27     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug(void)
{
	std::cout << "I love having extra bacon for my "
			  << "7XL-double-cheese-triple-pickle-special-ketchup "
			  << "burger. I really do!" << "\n";
}

void Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. "
			  << "You didn’t put enough bacon in my burger! "
			  << "If you did, I wouldn’t be asking for more!" << "\n";
}

void Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. "
			  << "I’ve been coming for years, "
			  << "whereas you started working here just last month." << "\n";
}

void Harl::error(void)
{
	std::cout << "This is unacceptable! "
			  << "I want to speak to the manager now." << "\n";
}

void Harl::complain(std::string level)
{
	void (Harl::*member_functions[4])() = {&Harl::debug,
										   &Harl::info,
										   &Harl::warning,
										   &Harl::error};

	std::string comments[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	size_t		iter = 0;
	while (iter < 4)
	{
		if (comments[iter] == level)
		{
			std::cout << std::left << std::setw(9) << level + ": ";
			(this->*member_functions[iter])();
			return;
		}
		iter++;
	}
	std::cerr << "Error!\nInvalid input: \"" << level << "\"\n";
}
