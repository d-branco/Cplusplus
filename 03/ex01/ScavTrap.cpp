/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   ScavTrap.cpp                         :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/09/15 17:50:28      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/09/16 09:54:03     #########  #########  ###      ###      */
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

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(name_), mode_(0)
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
void ScavTrap::attack(const std::string &target)
{
	if ((this->hit_ == 0) || (this->energy_ == 0))
	{
		std::cout << this->name_ << " remains immovable.\n";
		return;
	}
	this->energy_--;
	std::cout << this->name_ << " deals " << this->attack_ << " to " << target
			  << " Still has " << this->energy_ << " energy.\n";
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
