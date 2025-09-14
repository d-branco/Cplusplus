/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   Fixed.cpp                            :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/09/05 20:02:19      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/09/08 17:16:17     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include "Fixed.hpp"

// ex00
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

// ex01
Fixed::Fixed(const int int_nbr)
{
	std::cout << "Int constructor called\n";
	value_ = int_nbr << fractional_bits_;
}

Fixed::Fixed(const float float_nbr)
{
	std::cout << "Float constructor called\n";
	value_ = roundf(float_nbr * (1 << fractional_bits_));
}

float Fixed::toFloat() const
{
	return (static_cast<float>(value_) / (1 << fractional_bits_));
}

int Fixed::toInt() const
{
	return (value_ >> fractional_bits_);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}

//ex02
