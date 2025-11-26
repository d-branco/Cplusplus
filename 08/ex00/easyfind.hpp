/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   easyfind.hpp                         :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/11/26 15:46:09      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/11/26 16:08:09     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#ifndef DEBUG
# define DEBUG false
#endif

#include <iostream>

template <class T> class Easyfind
{
  private:

  public:
	Easyfind()
	{
		if (DEBUG)
		{
			std::cout << "==DEBUG== Easyfind: Default Parametized Constructor\n";
		}
	}

	Easyfind(const Easyfind &other)
	{
		if (DEBUG)
		{
			std::cout << "==DEBUG== Easyfind: Copy Constructor\n";
		}
		*this = other;
	}

	Easyfind &operator=(const Easyfind &other)
	{
		if (DEBUG)
		{
			std::cout << "==DEBUG== Easyfind: Copy Operator Constructor\n";
		}
		if (this == &other)
		{
			return (*this);
		}

		return (*this);
	}

	~Easyfind()
	{
		if (DEBUG)
		{
			std::cout << "==DEBUG== Easyfind: Destructor\n";
		}
	}

	find(type T, int nbr)
	{
		if (DEBUG)
		{
			std::cout << "==DEBUG== Easyfind: find\n";
		}
	}
};

#endif
