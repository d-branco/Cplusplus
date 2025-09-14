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
	const Fixed x;
	const Fixed y;
	// anything else useful
	Point &operator=(const Point &other);

  public:
	Point();
	Point(const float x, const float y);

	Point(const Point &other);	

	~Point();

	const Fixed get_x() const;
	const Fixed get_y() const;
};
