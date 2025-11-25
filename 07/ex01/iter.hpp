/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   iter.hpp                             :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/11/25 14:42:58      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/11/25 17:01:36     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

template <typename T>
void iter(T *array, const size_t lenght, void (*function)(T &))
{
	size_t i = 0;
	for (;;)
	{
		function(array[i]);
		i++;
		if (i >= lenght)
			break;
	}
}

template <typename T>
void iter(const T *array, const size_t lenght, void (*function)(const T &))
{
	size_t i = 0;
	for (;;)
	{
		function(array[i]);
		i++;
		if (i >= lenght)
			break;
	}
}

template <typename T> void add_one(T &ori)
{
	ori++;
}

template <typename T> void print_the_next(T &ori)
{
	T temp = ori + 1;
	std::cout << "Next: '" << temp << "'\n";
}

#endif
