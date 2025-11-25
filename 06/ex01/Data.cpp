/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   Data.cpp                             :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/11/25 11:11:34      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/11/25 12:24:51     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include "Data.hpp"

///////////////////////////////////////////////////// Canonical Orthodox Form //
Data::Data()
{
	if (DEBUG)
	{
		std::cout << "==DEBUG== Data: Default Constructor\n";
	}
}

Data::Data(const Data &other)
{
	if (DEBUG)
	{
		std::cout << "==DEBUG== Data: Copy Constructor\n";
	}
	*this = other;
}

Data &Data::operator=(const Data &other)
{
	if (DEBUG)
	{
		std::cout << "==DEBUG== Data: Copy Operator Constructor\n";
	}
	if (this == &other)
	{
		return (*this);
	}
	this->secret_code = other.secret_code;

	return (*this);
}

Data::~Data()
{
	if (DEBUG)
	{
		std::cout << "==DEBUG== Data: Destructor\n";
	}
}

///////////////////////////////////////////////////////////////////// Getters //
///////////////////////////////////////////////////////////////////// Setters //
/////////////////////////////////////////////////////////////////// Functions //
