/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   ScalarConverter.hpp                  :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/11/23 10:56:57      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/11/23 12:55:22     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>

#ifndef DEBUG
# define DEBUG false
#endif

class ScalarConverter
{
  private:
	///////////////////////////////////////////////// Canonical Orthodox Form //
	ScalarConverter();
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter &operator=(const ScalarConverter &other);
	~ScalarConverter();

	/////////////////////////////////////////////////////////////// Variables //
	enum e_type
	{
		CHAR,
		INT,
		FLOAT,
		DOUBLE,
		PSEUDO,
		OTHER
	};

  public:
	/////////////////////////////////////////////////////////////// Functions //
	static void	  convert(const std::string &representation);
	static e_type detect_type(const std::string &representation);
};

#endif
