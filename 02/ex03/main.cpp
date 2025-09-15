/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   main.cpp                             :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/09/13 16:26:39      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/09/13 16:27:53     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

bool bsp(Point const a, Point const b, Point const c, Point const point);

int	 main(void)
{
	Point a(0, 0);
	Point b(4, 2);
	Point c(2, 4);

	Point p(1, 1);
	if (bsp(a, b, c, p) == true)
	{
		std::cout << "Point in the interior: True\n";
	}
	else
	{
		std::cout << "Point in the interior: False\n";
	}

	Point q(2, 1);
	if (bsp(a, b, c, q) == true)
	{
		std::cout << "Point in the edge: True\n";
	}
	else
	{
		std::cout << "Point in the edge: False\n";
	}

	Point r(0, 0);
	if (bsp(a, b, c, r) == true)
	{
		std::cout << "Point in the vertice: True\n";
	}
	else
	{
		std::cout << "Point in the vertice: False\n";
	}

	Point s(42, 42);
	if (bsp(a, b, c, s) == true)
	{
		std::cout << "Point in the exterior: True\n";
	}
	else
	{
		std::cout << "Point in the exterior: False\n";
	}

	return (0);
}
