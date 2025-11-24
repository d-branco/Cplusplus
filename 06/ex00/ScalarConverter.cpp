/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   ScalarConverter.cpp                  :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/11/23 10:56:57      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/11/24 18:23:29     #########  #########  ###      ###      */
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
		if (std::isprint(representation[0]) != 0)
		{
			std::cout << "char:   '" << static_cast<char>(representation[0])
					  << "'" << "\n";
		}
		else
		{
			std::cout << "char:   Non displayable\n";
		}
		std::cout << "int:    " << static_cast<int>(representation[0])
				  << "\nfloat:  " << static_cast<float>(representation[0])
				  << ".0f\ndouble: " << static_cast<double>(representation[0])
				  << ".0\n";

		return;
	}

	if (scalar_type == PSEUDO)
	{
		float  temp_f = 0;
		double temp_d = 0;

		std::cout << "char:   impossible" << "\nint:    impossible" << "\n";
		if ((representation == "nan") || (representation == "nanf"))
		{
			temp_f = std::numeric_limits<float>::quiet_NaN();
			temp_d = std::numeric_limits<double>::quiet_NaN();
		}
		else if ((representation == "-inf") || (representation == "-inff"))
		{
			temp_f = -std::numeric_limits<float>::infinity();
			temp_d = -std::numeric_limits<double>::infinity();
		}
		else
		{
			temp_f = +std::numeric_limits<float>::infinity();
			temp_d = +std::numeric_limits<double>::infinity();
		}
		std::cout << "float:  " << temp_f << "f\ndouble: " << temp_d << "\n";

		return;
	}

	if (
		(scalar_type == INT)
		|| (scalar_type == FLOAT)
		|| (scalar_type == DOUBLE))
	{
		double temp = std::strtod(representation.c_str(), NULL);

		if (temp < 0 || temp > 127)
		{
			std::cout << "char:   impossible\n";
		}
		else if (std::isprint(static_cast<char>(temp)))
		{
			std::cout << "char:   '" << static_cast<char>(temp) << "'\n";
		}
		else
		{
			std::cout << "char:   Non displayable\n";
		}

		if ((temp > std::numeric_limits<int>::max())
			|| (temp < std::numeric_limits<int>::min()))
		{
			std::cout << "int:    impossible\n";
		}
		else
		{
			std::cout << "int:    " << static_cast<int>(temp) << "\n";
		}

		if (temp == static_cast<int>(temp))
		{
			std::cout << "float:  " << static_cast<float>(temp) << ".0f\n";
		}
		else
		{
			std::cout << "float:  " << static_cast<float>(temp) << "f\n";
		}

		return;
	}
}

ScalarConverter::e_type
ScalarConverter::detect_type(const std::string &representation)
{
	if (representation.empty())
	{
		std::cout << "==DEBUG== lenght == 0\n";
		return (OTHER);
	}
	size_t i = 0;
	for (;;)
	{
		if ((std::isdigit(representation[i]) != 0)
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
		if (DEBUG)
		{
			std::cout << "==DEBUG== detect_type: not an INT\n";
		}
		break;
	}

	if (representation.length() == 1)
	{
		if (DEBUG)
		{
			std::cout << "==DEBUG== detect_type: CHAR\n";
		}
		return (CHAR);
	}
	if (DEBUG)
	{
		std::cout << "==DEBUG== detect_type: not an CHAR\n";
	}

	if (representation == "inff" || representation == "inf"
		|| representation == "-inff" || representation == "+inff"
		|| representation == "nan" || representation == "-inf"
		|| representation == "+inf" || representation == "nanf")
	{
		if (DEBUG)
		{
			std::cout << "==DEBUG== detect_type: PSEUDO-LITERAL\n";
		}
		return (PSEUDO);
	}
	if (DEBUG)
	{
		std::cout << "==DEBUG== detect_type: not an PSEUDO-LITERAL\n";
	}

	i			  = 0;
	size_t n_dots = 0;
	for (;;)
	{
		if ((std::isdigit(representation[i]) != 0)
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
			if (DEBUG)
			{
				std::cout << "==DEBUG== detect_type: not a double\n";
			}
			break;
		}
		if (representation[i] == '\0')
		{
			if (DEBUG)
			{
				std::cout << "==DEBUG== detect_type: DOUBLE\n";
			}
			return (DOUBLE);
		}
		if (DEBUG)
		{
			std::cout << "==DEBUG== detect_type: not a DOUBLE\n";
		}
		break;
	}

	i	   = 0;
	n_dots = 0;
	for (;;)
	{
		if ((0 != std::isdigit(representation[i]))
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
			if (DEBUG)
			{
				std::cout << "==DEBUG== detect_type: not a float\n";
			}
			break;
		}
		if ((representation[i] == 'f') && (representation[i + 1] == '\0'))
		{
			if (DEBUG)
			{
				std::cout << "==DEBUG== detect_type: FLOAT\n";
			}
			return (FLOAT);
		}

		if (DEBUG)
		{
			std::cout << "==DEBUG== detect_type: not a FLOAT\n";
		}
		break;
	}

	if (DEBUG)
	{
		std::cout << "==DEBUG== detect_type: no type found!\n";
	}
	return (OTHER);
}
