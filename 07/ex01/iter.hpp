/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   iter.hpp                             :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/11/25 14:42:58      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/11/25 16:36:22     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

template <typename T, typename U>
void iter(T *array, const size_t lenght, U function)
{
	size_t i = 0;
	for (;;)
	{
		array[i] = function(array[i]);
		i++;
		if (i >= lenght)
		{
			break;
		}
	}
}

#endif
