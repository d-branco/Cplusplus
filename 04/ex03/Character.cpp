/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   Character.cpp                        :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/09/27 11:38:23      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/09/27 11:39:11     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include "Character.hpp"

    std::string const &Character::getName() const
	{
		if (DEBUG)
		{
			std::cout << "Character: :getName()\n";
		}
		return (this->name_);
	}

    void               ICharacter::equip(AMateria *m)
	{
		if (DEBUG)
		{
			std::cout << "Character: equip(AMateria *m)\n";
		}
	}

    void               ICharacter::unequip(int idx)
	{
		if (DEBUG)
		{
			std::cout << "Character: unequip(int idx)\n";
		}
	}

    void               ICharacter::use(int idx, ICharacter &target)
	{
		if (DEBUG)
		{
			std::cout << "Character: use(int idx, ICharacter &target)\n";
		}
	}