/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   HumanA.hpp                           :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/08/31 18:43:04      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/08/31 18:57:30     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#ifndef HUMANA_H
#define HUMANA_H

#include "Weapon.hpp"

class HumanA
{
  private:
	std::string name;
	Weapon	   &weapon_type;

  public:
	HumanA(std::string name, Weapon &weapon_type);

	void   setWeapon(Weapon &new_weapon);
	Weapon get_weapon();

	void   attack();
};

#endif
