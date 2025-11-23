/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   ScalarConverter.cpp                  :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/11/23 10:56:57      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/11/23 14:24:03     #########  #########  ###      ###      */
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
		std::cout << "==DEBUG== convert: input: " << representation << "\n";
	}

	ScalarConverter::e_type scalar_type
		= ScalarConverter::detect_type(representation);
	if (scalar_type == OTHER)
	{
		std::cout << "Error:\n  Unrecognized scalar!\n";
		return;
	}

	if (scalar_type == CHAR)
	{
		std::cout << "char:  '" << representation[0] << "'"
				  << "\nint:    " << static_cast<int>(representation[0])
				  << "\nfloat:  " << static_cast<float>(representation[0])
				  << ".0f"
				  << "\ndouble: " << static_cast<double>(representation[0])
				  << ".0" << "\n";
		return;
	}

	if (scalar_type == PSEUDO)
	{
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
			if ((DEBUG)
				&& (((representation[i]) == '-')
					|| ((representation[i]) == '+')))
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

	i			  = 0;
	size_t n_dots = 0;
	for (;;)
	{
		if ((std::isdigit(representation[i]))
			|| ((i == 0)
				&& (((representation[i]) == '-')
					|| ((representation[i]) == '+'))))
		{
			if ((DEBUG)
				&& (((representation[i]) == '-')
					|| ((representation[i]) == '+')))
			{
				std::cout << "==DEBUG== detect_type: sign detected!\n";
			}
			i++;
			continue;
		}
		if (representation[i] == '.')
		{
			if (DEBUG)
			{
				std::cout << "==DEBUG== detect_type: dot detected!\n";
			}
			if (n_dots == 0)
			{
				n_dots++;
				i++;
				continue;
			}
			else
			{
				if (DEBUG)
				{
					std::cout << "==DEBUG== detect_type: not a double\n";
				}
				break;
			}
		}
		if (representation[i] == '\0')
		{
			if (DEBUG)
			{
				std::cout << "==DEBUG== detect_type: DOUBLE\n";
			}
			return (DOUBLE);
		}
		else
		{
			if (DEBUG)
			{
				std::cout << "==DEBUG== detect_type: not a DOUBLE\n";
			}
			break;
		}
	}

	i	   = 0;
	n_dots = 0;
	for (;;)
	{
		if ((std::isdigit(representation[i]))
			|| ((i == 0)
				&& (((representation[i]) == '-')
					|| ((representation[i]) == '+'))))
		{
			if ((DEBUG)
				&& (((representation[i]) == '-')
					|| ((representation[i]) == '+')))
			{
				std::cout << "==DEBUG== detect_type: sign detected!\n";
			}
			i++;
			continue;
		}
		if (representation[i] == '.')
		{
			if (DEBUG)
			{
				std::cout << "==DEBUG== detect_type: dot detected!\n";
			}
			if (n_dots == 0)
			{
				n_dots++;
				i++;
				continue;
			}
			else
			{
				if (DEBUG)
				{
					std::cout << "==DEBUG== detect_type: not a float\n";
				}
				break;
			}
		}
		if ((representation[i] == 'f') && (representation[i + 1] == '\0'))
		{
			if (DEBUG)
			{
				std::cout << "==DEBUG== detect_type: FLOAT\n";
			}
			return (FLOAT);
		}
		else
		{
			if (DEBUG)
			{
				std::cout << "==DEBUG== detect_type: not a FLOAT\n";
			}
			break;
		}
	}

	if (DEBUG)
	{
		std::cout << "==DEBUG== detect_type: no type found!\n";
	}
	return (OTHER);
}
