/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   Fixed.cpp                            :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/09/13 16:26:39      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/09/13 16:28:14     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include "Fixed.hpp"

//////////////////////////////////////////////////////////////////////// ex00 //
Fixed::Fixed()
{
	//std::cout << "Default constructor called\n";
	value_ = 0;
}

Fixed::Fixed(const Fixed &other)
{
	//std::cout << "Copy constructor called\n";
	this->value_ = other.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &other)
{
	//std::cout << "Copy assignment operator called\n";
	if (this != &other)
	{
		this->value_ = other.value_;
	}
	return (*this);
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called\n";
}

int Fixed::getRawBits() const
{
	//std::cout << "getRawBits member function called\n";
	return (value_);
}

void Fixed::setRawBits(int const raw)
{
	//std::cout << "setRawBits member function called\n";
	this->value_ = raw;
}

//////////////////////////////////////////////////////////////////////// ex01 //
Fixed::Fixed(const int int_nbr)
{
	//std::cout << "Int constructor called\n";
	value_ = int_nbr << fractional_bits_;
}

Fixed::Fixed(const float float_nbr)
{
	//std::cout << "Float constructor called\n";
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

//////////////////////////////////////////////////////////////////////// ex02 //
bool	Fixed::operator>(const Fixed &other) const
{
	return (this->value_ > other.getRawBits());
}

bool	Fixed::operator>=(const Fixed &other) const
{
	return (this->value_ >= other.getRawBits());
}

bool	Fixed::operator<(const Fixed &other) const
{
	return (this->value_ < other.getRawBits());
}

bool	Fixed::operator<=(const Fixed &other) const
{
	return (this->value_ <= other.getRawBits());
}

bool	Fixed::operator==(const Fixed &other) const
{
	return (this->value_ == other.getRawBits());
}

bool	Fixed::operator!=(const Fixed &other) const
{
	return (this->value_ != other.getRawBits());
}


Fixed Fixed::operator+(const Fixed &other)
{
	return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed Fixed::operator-(const Fixed &other)
{
	return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed Fixed::operator*(const Fixed &other)
{
	return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed Fixed::operator/(const Fixed &other)
{
	return (Fixed(this->toFloat() / other.toFloat()));
}


Fixed &Fixed::operator++()		// Increments before
{
	this->value_++;
	return(*this);
}

Fixed Fixed::operator++(int)	// Increments after
{
	Fixed	temp = *this;
	Fixed::operator++();
	return (temp);
}

Fixed &Fixed::operator--()		// Decrements before
{
	this->value_--;
	return(*this);
}

Fixed Fixed::operator--(int)	// Decrements after
{
	Fixed	temp = *this;
	Fixed::operator--();
	return (temp);
}



Fixed &Fixed::min(Fixed &first, Fixed &second)
{
	if (first < second)
	{
		return (first);
	}
	else
	{
		return(second);
	}
}

const Fixed &Fixed::min(const Fixed &first, const Fixed &second)
{
	if (first < second)
	{
		return (first);
	}
	else
	{
		return(second);
	}
}

Fixed &Fixed::max(Fixed &first, Fixed &second)
{
	if (first > second)
	{
		return (first);
	}
	else
	{
		return(second);
	}
}

const Fixed &Fixed::max(const Fixed &first, const Fixed &second)
{
	if (first > second)
	{
		return (first);
	}
	else
	{
		return(second);
	}
}
