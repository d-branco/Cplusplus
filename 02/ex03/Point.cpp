/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   Point.cpp                            :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/09/14 11:43:53      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/09/14 11:45:04     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0)
{
}

Point::Point(float x, float y) : x(x), y(y)
{
}

Point::Point(const Point &other) : x(other.x), y(other.y)
{
}

Point &Point::operator=(const Point &other)
{
	(void) &other;
	return (*this);
}

Point::~Point()
{
}

const Fixed Point::get_x() const
{
	return (x);
}

const Fixed Point::get_y() const
{
	return (y);
}

