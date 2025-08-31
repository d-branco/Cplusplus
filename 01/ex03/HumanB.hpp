/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   HumanB.hpp                           :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/08/31 18:13:34      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/08/31 18:14:24     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#ifndef HUMANB_H
#define HUMANB_H

#include "Weapon.hpp"

class HumanB
{
  private:
	Weapon		weapon_type;
	std::string name;

  public:
	HumanB(std::string name);

	void   setWeapon(Weapon weapon_b);
	Weapon get_weapon();

	void   attack();
};

#endif
