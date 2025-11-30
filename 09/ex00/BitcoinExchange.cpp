/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   BitcoinExchange.cpp                  :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/11/30 15:48:54      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/11/30 15:48:54     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

///////////////////////////////////////////////////// Canonical Orthodox Form //
BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	*this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this == &other)
	{
		return (*this);
	}

	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

///////////////////////////////////////////////////////////////////// Getters //
///////////////////////////////////////////////////////////////////// Setters //
/////////////////////////////////////////////////////////////////// Functions //
