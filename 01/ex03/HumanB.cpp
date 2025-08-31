/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   HumanB.cpp                           :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/08/31 18:44:41      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/08/31 18:48:57     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name, Weapon &weapon) :
	name(name),
	weapon_type(weapon)
{
}

HumanB::HumanB(std::string name) : name(name), weapon_type(Weapon(""))
{
}

void HumanB::setWeapon(Weapon new_weapon)
{
	weapon_type = new_weapon;
}

Weapon HumanB::get_weapon()
{
	return (weapon_type);
}

void HumanB::attack()
{
}
