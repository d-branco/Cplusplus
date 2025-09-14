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
	Point a(0,0);
	Point b(4,2);
	Point c(2,4);

	Point p(1,1);

	if (bsp(a, b, c, p) == true)
	{
		std::cout << "Funciona!\n";
	}
	else
	{
		std::cout << "Nao funciona correctamente!\n";
	}

	return (0);
}
