/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   ClapTrap.cpp                         :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/09/15 15:12:35      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/09/15 15:18:05     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string &name) :
	name_(name),
	hit_(10),
	energy_(10),
	attack_(0)
{
	std::cout << this->name_ << " online.\n";
}

ClapTrap::ClapTrap(const ClapTrap &other) :
	name_(other.name_),
	hit_(other.hit_),
	energy_(other.energy_),
	attack_(other.attack_)
{
	std::cout << this->name_ << " online.\n";
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	this->name_	  = other.name_;
	this->hit_	  = other.hit_;
	this->energy_ = other.energy_;
	this->attack_ = other.attack_;

	std::cout << this->name_ << " online.\n";

	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << this->name_ << " offline.\n";
}

std::string ClapTrap::get_name()
{
	return (this->name_);
}

unsigned int ClapTrap::get_hit()
{
	return (this->hit_);
}

void ClapTrap::increment_hit(int change)
{
	if (-change > (int) this->hit_)
	{
		this->hit_ = 0;
	}
	this->hit_ += change;
}

void ClapTrap::attack(const std::string &target)
{
	if ((this->hit_ == 0) || (this->energy_ == 0))
	{
		std::cout << this->name_ << " stays still.\n";
		return;
	}
	std::cout << this->name_ << " attacks " << target << " dealing "
			  << this->attack_ << " damage!\n";
	this->energy_--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hit_ == 0)
	{
		std::cout << this->name_ << " remains immovable.\n";
	}
	std::cout << this->name_ << " takes " << amount << "damage!\n";
	ClapTrap::increment_hit(-amount);
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if ((this->hit_ == 0) || (this->energy_ == 0))
	{
		std::cout << this->name_ << " stays still.\n";
	}
	this->energy_--;
	ClapTrap::increment_hit(amount);
	std::cout << this->name_ << " recovers " << amount << " hit points. Has "
			  << this->hit_ << " total.\n";
}
