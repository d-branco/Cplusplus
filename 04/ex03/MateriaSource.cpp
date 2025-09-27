/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   MateriaSource.cpp                    :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/09/20 16:45:11      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/09/20 16:45:40     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	if (DEBUG)
	{
		std::cout << "MateriaSource: Default Constructor\n";
	}
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	if (DEBUG)
	{
		std::cout << "MateriaSource: Copy Constructor\n";
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
			std::cout << "           Copying itself!\n";
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
		std::cout << "MaterialSource: Default Destructor\n";
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

void	  MateriaSource::learnMateria(AMateria *new_materia)
{
	if (DEBUG)
	{
		std::cout << "MaterialSource: learnMateria()\n";
	}

	int i = 0;
	for (;;)
	{
		if (!this->inventory_[i])
		{
			this->inventory_[i] = new_materia;
		}
		i++;
		if (i >= INVENTORY_SIZE)
		{
			break;
		}
	}

}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	if (DEBUG)
	{
		std::cout << "MaterialSource: createMateria()\n";
	}

	int i = 0;
	for (;;)
	{
		if (inventory_[i] && inventory_[i]->getType() == type)
		{
			if (DEBUG)
			{
				std::cout	<< "                created "
							<< inventory_[i]->getType() << "\n";
			}
			return (inventory_[i]->clone());
		}
		i++;
		if (i >= INVENTORY_SIZE)
		{
			break;
		}
	}
	if (DEBUG)
	{
		std::cout	<< "                unknown type!\n";
	}
	return (0);
}
