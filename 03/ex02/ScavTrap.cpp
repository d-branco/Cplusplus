/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   ScavTrap.cpp                         :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/09/16 05:57:08      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/09/18 14:24:30     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include "ScavTrap.hpp"

///////////////////////////////////////////////////// Canonical Orthodox Form //
ScavTrap::ScavTrap(std::string name_) : ClapTrap(name_), mode_(0)
{
	hit_	= 100;
	energy_ = 50;
	attack_ = 20;
	std::cout << this->name_ << " booting up.\n";
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(""), mode_(0)
{
	*this = other;
	std::cout << this->name_ << " booting up.\n";
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
	{
		this->name_	  = other.name_;
		this->hit_	  = other.hit_;
		this->energy_ = other.energy_;
		this->attack_ = other.attack_;
	}
	std::cout << this->name_ << " booting up.\n";
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << this->name_ << " powering down.\n";
}

/////////////////////////////////////////////////////////////////// Functions //
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
