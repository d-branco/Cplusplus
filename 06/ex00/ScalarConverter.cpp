/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   ScalarConverter.cpp                  :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/11/23 10:56:57      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/11/23 13:34:04     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cstddef>

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

/////////////////////////////////////////////////////////////////// Functions //
void ScalarConverter::convert(const std::string &representation)
{
	if (DEBUG)
	{
		std::cout << "==DEBUG== input: " << representation << "\n";
	}

	ScalarConverter::e_type scalar_type
		= ScalarConverter::detect_type(representation);
	if (DEBUG)
	{
		std::cout << "==DEBUG== type: " << scalar_type << "\n";
	}
	if (scalar_type == OTHER)
	{
		return;
	}
}

ScalarConverter::e_type
ScalarConverter::detect_type(const std::string &representation)
{
	if (representation.length() == 0)
	{
		std::cout << "==DEBUG== lenght == 0\n";
		return (OTHER);
	}
	size_t i = 0;
	for (;;)
	{
		if ((std::isdigit(representation[i]))
			|| ((i == 0)
				&& (((representation[i]) == '-')
					|| ((representation[i]) == '+'))))
		{
			if (DEBUG)
			{
				std::cout << "==DEBUG== detect_type: sign detected!\n";
			}
			i++;
			continue;
		}
		if (representation[i] == '\0')
		{
			if (DEBUG)
			{
				std::cout << "==DEBUG== detect_type: INT\n";
			}
			return (INT);
		}
		else
		{
			if (DEBUG)
			{
				std::cout << "==DEBUG== detect_type: not an INT\n";
			}
			break;
		}
	}

	if (representation.length() == 1)
	{
		if (DEBUG)
		{
			std::cout << "==DEBUG== detect_type: CHAR\n";
		}
		return (CHAR);
	}
	else if (DEBUG)
	{
		std::cout << "==DEBUG== detect_type: not an CHAR\n";
	}

	if (representation == "-inff" || representation == "+inff"
		|| representation == "nan" || representation == "-inf"
		|| representation == "+inf" || representation == "nanf")
	{
		if (DEBUG)
		{
			std::cout << "==DEBUG== detect_type: PSEUDO-LITERAL\n";
		}
		return (PSEUDO);
	}
	else if (DEBUG)
	{
		std::cout << "==DEBUG== detect_type: not an PSEUDO-LITERAL\n";
	}

	if (DEBUG)
	{
		std::cout << "==DEBUG== detect_type: no type found!\n";
	}
	return (OTHER); // remove me, please
}
