/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   FragTrap.cpp                         :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/09/16 06:16:33      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/09/16 06:34:06     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include "FragTrap.hpp"

///////////////////////////////////////////////////// Canonical Orthodox Form //
FragTrap::FragTrap(std::string name_) : ClapTrap(name_)
{
	hit_	= 100;
	energy_ = 100;
	attack_ = 30;
	std::cout << this->name_ << " starts running.\n";
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(name_)
{
	*this = other;
	std::cout << this->name_ << " starts running.\n";
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	if (this != &other)
	{
		this->name_	  = other.name_;
		this->hit_	  = other.hit_;
		this->energy_ = other.energy_;
		this->attack_ = other.attack_;
	}
	std::cout << this->name_ << " starts running.\n";
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << this->name_ << " ends running.\n";
}

/////////////////////////////////////////////////////////////////// Functions //
void FragTrap::highFivesGuys(void)
{
	std::cout << this->name_ << ": \"High-fives, you guys!\"\n";
}
