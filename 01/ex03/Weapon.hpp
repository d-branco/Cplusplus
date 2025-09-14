/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   Weapon.hpp                           :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/08/31 17:55:30      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/08/31 18:52:25     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
#include <string>

class Weapon
{
  private:
	std::string type;

  public:
	Weapon(std::string type);

	std::string getType();
	void		setType(std::string new_type);
};

#endif
