/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   HumanA.cpp                           :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/08/31 18:27:08      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/08/31 18:35:39     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) :
	name(name),
	weapon_type(weapon)
{
}

void HumanA::setWeapon(Weapon new_weapon)
{
	weapon_type = new_weapon;
}

Weapon HumanA::get_weapon()
{
	return (weapon_type);
}

void HumanA::attack()
{
}
