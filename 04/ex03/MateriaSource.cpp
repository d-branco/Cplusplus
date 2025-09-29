/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   MateriaSource.cpp                    :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/09/29 07:45:24      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/09/29 08:03:50     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	if (DEBUG)
	{
		std::cout << "MateriaSource: Default Constructor\n";
	}

	int i = 0;
	for (;;)
	{
		inventory_[i] = NULL;
		i++;
		if (i >= INVENTORY_SIZE)
		{
			break;
		}
	}
	debug_print_inventory();
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	if (DEBUG)
	{
		std::cout << "MateriaSource: Copy Constructor\n";
	}

	int i = 0;
	for (;;)
	{
		inventory_[i] = NULL;
		i++;
		if (i >= INVENTORY_SIZE)
		{
			break;
		}
	}
	*this = other;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	if (DEBUG)
	{
		std::cout << "MateriaSource: Copy Operator= Constructor\n";
	}
	if (this == &other)
	{
		if (DEBUG)
		{
			std::cout << "               Copying itself!\n";
		}
		return (*this);
	}

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

MateriaSource::~MateriaSource()
{
	if (DEBUG)
	{
		std::cout << "MateriaSource: Default Destructor\n";
	}

	int i = 0;
	for (;;)
	{
		if (this->inventory_[i])
		{
			delete this->inventory_[i];
		}
		i++;
		if (i >= INVENTORY_SIZE)
		{
			break;
		}
	}
}

void MateriaSource::learnMateria(AMateria *new_materia)
{
	if (DEBUG)
	{
		std::cout << "MateriaSource: learnMateria(" << new_materia->getType()
				  << ")\n";
	}

	int i = 0;
	for (;;)
	{
		if (!this->inventory_[i])
		{
			this->inventory_[i] = new_materia;
			break;
		}
		i++;
		if (i >= INVENTORY_SIZE)
		{
			break;
		}
	}
	debug_print_inventory();
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	if (DEBUG)
	{
		std::cout << "MateriaSource: createMateria(" << type << ")\n";
	}

	int i = 0;
	for (;;)
	{
		if (inventory_[i] && (inventory_[i]->getType() == type))
		{
			if (DEBUG)
			{
				std::cout << "                created "
						  << inventory_[i]->getType() << "\n";
			}
			debug_print_inventory();
			return (inventory_[i]->clone());
		}
		i++;
		if (i >= INVENTORY_SIZE)
		{
			break;
		}
	}
	debug_print_inventory();
	if (DEBUG)
	{
		std::cout << "                unknown type!\n";
	}
	return (0);
}

void MateriaSource::debug_print_inventory()
{
	if (!DEBUG)
		return;

	int i = 0;
	for (;;)
	{
		if (inventory_[i])
		{
			if (DEBUG)
			{
				std::cout << "    " << i << ": " << inventory_[i]->getType()
						  << "\n";
			}
		}
		else if (inventory_[i] == NULL)
		{
			std::cout << "    " << i << ": NULL\n";
		}
		i++;
		if (i >= INVENTORY_SIZE)
		{
			break;
		}
	}
}
