/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   ScalarConverter.cpp                  :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/11/23 10:56:57      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/11/23 11:24:11     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

///////////////////////////////////////////////////// Canonical Orthodox Form //
ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	*this = other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	if (this == &other)
	{
		return (*this);
	}

	return (*this);
}

ScalarConverter::~ScalarConverter()
{
}

///////////////////////////////////////////////////////////////////// Getters //
///////////////////////////////////////////////////////////////////// Setters //
/////////////////////////////////////////////////////////////////// Functions //
void	ScalarConverter::convert(std::string representation)
{
	(void) representation;
}
