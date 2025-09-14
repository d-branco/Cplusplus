/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   main.cpp                             :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/09/02 16:36:43      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/09/02 16:37:59     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main( void )
{
	Fixed			a;
	Fixed const		b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

	// std::cout << "\n";
	// std::cout << Fixed::min( a, b ) << std::endl;

	// std::cout << "\n";
	// std::cout << (a > b) << "\n";
	// std::cout << (a >= b) << "\n";
	// std::cout << (a < b) << "\n";
	// std::cout << (a <= b) << "\n";
	// std::cout << (a == b) << "\n";
	// std::cout << (a != b) << "\n";

	// std::cout << "\n";
	// std::cout << (1 + 1) << "\n";
	// std::cout << (4 - 2) << "\n";
	// std::cout << (4.2 * 4.2) << "\n";
	// std::cout << (20.25 / 9) << "\n";

	return 0;
}
