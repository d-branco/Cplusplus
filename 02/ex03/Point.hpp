/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   Point.hpp                            :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/09/13 18:49:24      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/09/14 11:43:47     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

class Point
{
  private:
	Fixed x;
	Fixed y;
	// anything else useful

  public:
	Point();
	Point(float x, float y);

	Point(const Point &other);
	Point &operator=(const Point &other);

	~Point();

	Fixed get_x() const;
	Fixed get_y() const;
	void  set_x(Fixed fix_nbr);
	void  set_y(Fixed fix_nbr);
};
