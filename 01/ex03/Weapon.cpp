/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   Weapon.cpp                           :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/08/31 17:48:40      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/08/31 18:52:16     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include "Weapon.hpp"

std::string Weapon::getType()
{
	return (type);
}

void Weapon::setType(std::string new_type)
{
	this->type = new_type;
}

Weapon::Weapon(std::string type) : type(type)
{
}
