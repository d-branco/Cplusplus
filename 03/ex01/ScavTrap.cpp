/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   ScavTrap.cpp                         :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/09/15 16:34:06      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/09/15 17:28:32     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name_) : ClapTrap(name_)
{
	mode_ = 0;
	hit_ = 100;
	energy_ = 50;
	attack_ = 20;
	std::cout << this->name_ << " booting up.\n";
}

void ScavTrap::guardGate()
{
	if (this->mode_ == 0)
	{
		this->mode_ = 1;
		std::cout << this->name_ << " mode: Gate keeper.\n";
	}
	else if (this->mode_ == 1)
	{
		std::cout << this->name_ << " mode: Gate keeper still.\n";
	}
}

ScavTrap::~ScavTrap()
{
	std::cout << this->name_ << " powering down.\n";
}
