/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   ClapTrap.cpp                         :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/09/15 11:18:03      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/09/15 11:25:23     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string &name) :
	name_(name),
	hit_(10),
	energy_(10),
	attack_(0)
{
}

ClapTrap::ClapTrap(const ClapTrap &other) :
	name_(other.name_),
	hit_(other.hit_),
	energy_(other.energy_),
	attack_(other.attack_)
{
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	this->name_	  = other.name_;
	this->hit_	  = other.hit_;
	this->energy_ = other.energy_;
	this->attack_ = other.attack_;

	return (*this);
}

ClapTrap::~ClapTrap()
{
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
	(void) target;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	(void) amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	(void) amount;
}
