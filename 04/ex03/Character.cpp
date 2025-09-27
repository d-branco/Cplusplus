/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   Character.cpp                        :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/09/27 16:02:21      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/09/27 16:10:29     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : name_("Protagonist"), inventory_()
{
	if (DEBUG)
	{
		std::cout << "Character: Default Constructor\n";
		std::cout << "           name_:" << this->name_ << "\n";
	}
}

Character::Character(const Character &other) : ICharacter(other)
{
	if (DEBUG)
	{
		std::cout << "Character: Copy Constructor\n";
		std::cout << "           name_:" << other.name_ << "\n";
	}

	*this = other;
}

Character &Character::operator=(const Character &other)
{
	if (DEBUG)
	{
		std::cout << "Character: Copy Operator= Constructor\n";
	}
	if (this == &other)
	{
		if (DEBUG)
		{
			std::cout << "           Copying itself!\n";
		}

		return (*this);
	}

	this->name_ = other.name_;
	// deep copy inventory
	int i = 0;
	for (;;)
	{
		if (this->inventory_[i])
		{
			delete inventory_[i];
			inventory_[i] = NULL;
		}
		if (other.inventory_[i])
		{
			this->inventory_[i] = other.inventory_[i]->clone();
			if (DEBUG)
			{
				std::cout << "           Copied: "
						  << this->inventory_[i]->getType() << "\n";
			}
		}
		i++;
		if (i >= INVENTORY_SIZE)
		{
			break;
		}
	}

	return (*this);
}

Character::~Character()
{
	if (DEBUG)
	{
		std::cout << "Character: Destructor\n";
	}

	int i = 0;
	for (;;)
	{
		if (this->inventory_[i])
		{
			delete this->inventory_[i];
			this->inventory_[i] = NULL;
		}
		i++;
		if (i >= INVENTORY_SIZE)
		{
			break;
		}
	}
}

std::string const &Character::getName() const
{
	if (DEBUG)
	{
		std::cout << "Character: getName()\n";
	}
	return (this->name_);
}

void Character::equip(AMateria *m)
{
	if (DEBUG)
	{
		std::cout << "Character: equip(" << m->getType() << ")\n";
	}
	int i = 0;
	for (;;)
	{
		if (this->inventory_[i] == NULL)
		{
			inventory_[i] = m;
			break;
		}
		i++;
		if (i >= INVENTORY_SIZE)
		{
			if (DEBUG)
			{
				std::cout << "           Insuficient inventory size!\n";
			}
			break;
		}
	}
}

void Character::unequip(int idx)
{
	if (DEBUG)
	{
		std::cout << "Character: unequip(" << inventory_[idx]->getType()
				  << ")\n";
	}
	leave_on_the_floor(inventory_[idx]);
	inventory_[idx] = NULL;
}

void Character::leave_on_the_floor(AMateria *m)
{
	delete m;
}

void Character::use(int idx, ICharacter &target)
{
	if (DEBUG)
	{
		std::cout << "Character: use(" << inventory_[idx]->getType() << ")\n";
	}
	this->inventory_[idx]->use(target);
}
