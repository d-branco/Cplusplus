/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   HumanA.hpp                           :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/08/31 18:13:34      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/08/31 18:14:29     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#ifndef HUMANA_H
#define HUMANA_H

#include "Weapon.hpp"

class HumanA
{
  private:
	Weapon		weapon_type;
	std::string name;

  public:
	HumanA(std::string name, Weapon weapon_a);

	void   setWeapon(Weapon weapon_a);
	Weapon get_weapon();

	void   attack();
};

#endif
