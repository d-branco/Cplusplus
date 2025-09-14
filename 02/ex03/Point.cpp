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
	this->x = other.x;
	this->y = other.y;
	return (*this);
}

Point::~Point()
{
}

Fixed Point::get_x() const
{
	return (x);
}

Fixed Point::get_y() const
{
	return (y);
}

void Point::set_x(Fixed fix_nbr)
{
	this->x = fix_nbr;
}

void Point::set_y(Fixed fix_nbr)
{
	this->y = fix_nbr;
}
