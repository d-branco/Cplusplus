/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   Fixed.hpp                            :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/09/02 16:11:41      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/09/02 16:23:15     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

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
	static const int nbr_fractional_bits; // always equal to 8

  public:
	Fixed();

	Fixed(const Fixed &other);
	Fixed &operator=(const Fixed &other);

	~Fixed();

	int	 getRawBits() const;
	void setRawBits(int raw);
};

#endif
