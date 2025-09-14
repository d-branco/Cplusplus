/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   bsp.cpp                              :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/09/13 16:26:39      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/09/13 16:27:35     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

// Binary Space Partitioning

#include "Point.hpp"

Fixed		distance_to_line(Point line0, Point line1, Point point);
Fixed		line_side(Point l_start, Point l_end, Point point);

bool		bsp(Point const a, Point const b, Point const c, Point const point)
{
	//check if there are any three points aligned
	if ((distance_to_line(a, b, c) == 0) || (distance_to_line(a, b, point) == 0)
		|| (distance_to_line(b, c, a) == 0) || (distance_to_line(b, c, point) == 0)
		|| (distance_to_line(c, a, b) == 0) || (distance_to_line(c, a, point) == 0))
		return (false);

	//check if point is on the same side as the remaining vertice
	if ((line_side(a, b, c) == line_side(a, b, point))
		&& (line_side(b, c, a) == line_side(b, c, point))
		&& (line_side(c, a, b) == line_side(c, a, point)))
		return (true);
	return (false);
}

Fixed		line_side(Point l_start, Point l_end, Point point)
{
	if (((l_end.get_x() - l_start.get_x()) * (point.get_y() - l_start.get_y())
			- (l_end.get_y() - l_start.get_y()) * (point.get_x() - l_start.get_x())) > 0)
		return (1);
	return (-1);
}


Fixed		distance_to_line(Point l_start, Point l_end, Point point)
{
	Fixed a = l_end.get_y() - l_start.get_y();
	Fixed b = l_start.get_x() - l_end.get_x();
	Fixed c = (l_end.get_x() * l_start.get_y())
					- (l_start.get_x() * l_end.get_y());

	Fixed num = (a * point.get_x()) + (b * point.get_y()) + c;
	if ((num == 0) || ((a == 0) && (b == 0)))
		return (0);
	else if (num < 0)
		num = (num * -1);
	return (num);
}