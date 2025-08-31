/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   HumanB.hpp                           :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/08/31 18:44:41      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/08/31 18:45:12     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#ifndef HUMANB_H
#define HUMANB_H

#include "Weapon.hpp"

class HumanB
{
  private:
	std::string name;
	Weapon		weapon_type;

  public:
	HumanB(std::string name, Weapon &weapon);
	HumanB(std::string name);

	void   setWeapon(Weapon new_weapon);
	Weapon get_weapon();

	void   attack();
};

#endif
