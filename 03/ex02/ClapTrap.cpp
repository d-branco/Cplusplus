/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   ClapTrap.cpp                         :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/09/15 16:31:42      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/09/15 17:48:14     #########  #########  ###      ###      */
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
	if (this != &other)
	{
		this->name_	  = other.name_;
		this->hit_	  = other.hit_;
		this->energy_ = other.energy_;
		this->attack_ = other.attack_;
	}

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
	if (-change >= ((int) this->hit_))
	{
		this->hit_ = 0;
		return;
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
	this->energy_--;
	std::cout << this->name_ << " attacks " << target << " dealing "
			  << this->attack_ << " damage! Has " << this->energy_
			  << " energy remaning.\n";
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hit_ == 0)
	{
		std::cout << this->name_ << " remains immovable.\n";
	}
	ClapTrap::increment_hit(-((int) amount));
	if (this->hit_ > 0)
	{
		std::cout << this->name_ << " takes " << ((int) amount)
				  << " damage! Has " << (int) this->hit_ << " hit points.\n";
	}
	else
	{
		std::cout << this->name_ << " can't take it anymore. Has "
				  << (int) this->hit_ << " hit points.\n";
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if ((this->hit_ == 0) || (this->energy_ == 0))
	{
		std::cout << this->name_ << " stays still.\n";
		return;
	}
	this->energy_--;
	ClapTrap::increment_hit(amount);
	std::cout << this->name_ << " recovers " << (int) amount
			  << " hit points. Has " << this->hit_ << " total. Has "
			  << this->energy_ << " energy remaning.\n";
}
