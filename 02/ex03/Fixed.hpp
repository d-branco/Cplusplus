/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   Fixed.hpp                            :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/09/13 16:26:39      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/09/13 16:27:48     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

#include <cmath>
#include <iostream>
#include <string>

//	Default		constructor
//
//	Copy		constructor
//	Copy		assignment operator
//
//	Destructor

class Fixed
{
  private:
	int				 value_;
	static const int fractional_bits_ = 8; // always equal to 8

  public:
	Fixed();

	Fixed(const Fixed &other);
	Fixed &operator=(const Fixed &other);

	~Fixed();

	int	 getRawBits() const;
	void setRawBits(int raw);

	Fixed(const int int_nbr);
	Fixed(const float float_nbr);

	float toFloat() const;
	int	  toInt() const;

	//ex02
	bool operator>(const Fixed &other) const;
	bool operator>=(const Fixed &other) const;
	bool operator<(const Fixed &other) const;
	bool operator<=(const Fixed &other) const;
	bool operator==(const Fixed &other) const;
	bool operator!=(const Fixed &other) const;

	Fixed operator+(const Fixed &other);
	Fixed operator-(const Fixed &other);
	Fixed operator*(const Fixed &other);
	Fixed operator/(const Fixed &other);

	Fixed &operator++();		// Increments before
	Fixed operator++(int);		// Increments after
	Fixed &operator--();		// Decrements before
	Fixed operator--(int);		// Decrements after

	static Fixed &min(Fixed &first, Fixed &second);
	const static Fixed &min(const Fixed &first, const Fixed &second);
	static Fixed &max(Fixed &first, Fixed &second);
	const static Fixed &max(const Fixed &first, const Fixed &second);
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
