/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   Serializer.cpp                       :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/11/25 10:55:58      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/11/25 11:04:31     #########  #########  ###      ###      */
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
