/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   Fixed.cpp                            :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/09/02 16:11:41      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/09/02 17:27:46     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <string>

Fixed::Fixed()
{
	std::cout << "Default constructor called\n";
	value_ = 0;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called\n";
	this->value_ = other.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called\n";
	if (this != &other)
	{
		this->value_ = other.getRawBits();
	}
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called\n";
	return (value_);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called\n";
	this->value_ = raw;
}
