/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   main.cpp                             :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/11/27 14:35:50      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/11/27 16:39:49     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include <cstdlib>

#include "Span.hpp"

#ifndef DEBUG
# define DEBUG false
#endif

int main(void)
{
	std::cout << "Vector with max size of 42. Adding 5 INT\n";
	Span vicky(42);
	vicky.addNumber(0);
	vicky.addNumber(42);
	vicky.addNumber(225);
	vicky.addNumber(2025);
	vicky.addNumber(-1);

	std::cout << "\nVector with max size of 2. Adding 3 INT\n";
	Span victoria(2);
	victoria.addNumber(-1);
	victoria.addNumber(-2);
	victoria.addNumber(-3);

	std::cout << "\nCopying vector with max size of 2. Adding 1 INT\n";
	Span victor(victoria);
	victor.addNumber(42);

	std::cout << "\nOperator copying  vector with max size of 2. Adding 1 "
				 "INT\n";
	Span vitor(victoria);
	vitor.addNumber(225);

	std::cout << "\nCode from the subject bellow:\n";
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	if (DEBUG)
	{
		std::cout << "\n==DEBUG== End of main()\n";
	}
	return (EXIT_SUCCESS);
}