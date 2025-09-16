/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   DiamondTrap.cpp                      :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/09/16 09:33:28      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/09/16 10:13:24     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

///////////////////////////////////////////////////// Canonical Orthodox Form //
DiamondTrap::DiamondTrap(std::string name) :
	ClapTrap(name + "_clap_name"),
	ScavTrap(name),
	FragTrap(name)
{
	name_	= name;
	//hit_	= FragTrap::hit_;
	energy_ = ScavTrap::initial_energy;
	//attack_ = FragTrap::attack_;
	std::cout << this->name_ << " suddenly shines.\n";

	std::cout << this->name_ << " has:\n    " << this->hit_
			  << " hit points\n    " << this->energy_ << " energy\n    "
			  << this->attack_ << " attack\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) :
	ClapTrap(name_),
	ScavTrap(name_),
	FragTrap(name_)
{
	*this = other;
	std::cout << this->name_ << " suddenly shines too.\n";
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	if (this != &other)
	{
		this->name_	  = other.name_;
		this->hit_	  = other.hit_;
		this->energy_ = other.energy_;
		this->attack_ = other.attack_;
	}
	std::cout << this->name_ << " suddenly shines too.\n";
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << this->name_ << " stops shinning.\n";
}

/////////////////////////////////////////////////////////////////// Functions //
void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "\"Who am I...? Am I " << this->name_ << " or just a simple "
			  << ClapTrap::name_ << ".\"\n";
}
