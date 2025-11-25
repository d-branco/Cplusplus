/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   template.hpp                         :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/11/25 14:32:00      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/11/25 14:39:10     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

template <typename T>
T max(T x, T y)
{
	if (x > y)
	{
		return (x);
	}
	return (y);
}

template <typename T>
T min(T x, T y)
{
	if (x < y)
	{
		return (x);
	}
	return (y);
}

template <typename T>
void swap(T &x, T &y)
{
	T temp = x;
	x = y;
	y = temp;
	return ;
}