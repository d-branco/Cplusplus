/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   Point.hpp                            :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/09/13 16:26:39      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/09/13 16:28:27     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

class Point
{
	private:
		const Fixed x;
		const Fixed y;
		//anything else useful

	public:
		Point();
		Point(float x, float y);

		Point(const Point &other);
		Point &operator=(const Point &other);

		~Point();

		Point	get_x() const;
		Point	get_y() const;
		void	set_x(Fixed fix_nbr);
		void	set_y(Fixed fix_nbr);

};


