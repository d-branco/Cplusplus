/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   Serializer.cpp                       :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/11/25 10:55:58      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/11/25 12:50:04     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include "Serializer.hpp"

///////////////////////////////////////////////////// Canonical Orthodox Form //
Serializer::Serializer()
{
	if (DEBUG)
	{
		std::cout << "==DEBUG== Serializer: Default Constructor\n";
	}
}

Serializer::Serializer(const Serializer &other)
{
	if (DEBUG)
	{
		std::cout << "==DEBUG== Serializer: Copy Constructor\n";
	}
	*this = other;
}

Serializer &Serializer::operator=(const Serializer &other)
{
	if (DEBUG)
	{
		std::cout << "==DEBUG== Serializer: Copy Operator Constructor\n";
	}
	if (this == &other)
	{
		return (*this);
	}

	return (*this);
}

Serializer::~Serializer()
{
	if (DEBUG)
	{
		std::cout << "==DEBUG== Serializer: Destructor\n";
	}
}

///////////////////////////////////////////////////////////////////// Getters //
///////////////////////////////////////////////////////////////////// Setters //
/////////////////////////////////////////////////////////////////// Functions //

// Takes a pointer and converts it to the unsigned integer type uintptr_t
uintptr_t Serializer::serialize(Data *ptr)
{
	if (DEBUG)
	{
		std::cout << "==DEBUG== Serializer: serialize " << ptr << "\n";
	}

	return (reinterpret_cast<uintptr_t>(ptr));
}

// Tkes an unsigned integer parameter and converts it to a pointer to Data
Data *Serializer::deserialize(uintptr_t raw)
{
	if (DEBUG)
	{
		std::cout << "==DEBUG== Serializer: deserialize " << raw << "\n";
	}

	return (reinterpret_cast<Data *>(raw));
}