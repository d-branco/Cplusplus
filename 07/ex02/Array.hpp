/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   Array.hpp                            :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/11/25 19:25:39      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/11/25 21:02:30     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#ifndef DEBUG
# define DEBUG false
#endif

#include <iostream>

template <class T> class Array
{
  private:
	T			*ele_;
	unsigned int ene_;

  public:
	Array() : ele_(new T[0]), ene_(0)
	{
		if (DEBUG)
		{
			std::cout << "==DEBUG== Array: Default Constructor: Empty array\n";
		}
	}

	Array(unsigned int ene) : ele_(new T[ene]), ene_(ene)
	{
		if (DEBUG)
		{
			std::cout << "==DEBUG== Array: Default Parametrized Constructor: "
						 "Array (size: "
					  << ene_ << ")\n";
		}
	}

	Array(const Array &other)
	{
		if (DEBUG)
		{
			std::cout << "==DEBUG== Array: Copy Constructor\n";
		}
		*this = other;
	}

	Array &operator=(const Array &other)
	{
		if (DEBUG)
		{
			std::cout << "==DEBUG== Array: Copy Operator Constructor\n";
		}
		if (this == &other)
		{
			return (*this);
		}

		return (*this);
	}

	~Array()
	{
		if (DEBUG)
		{
			std::cout << "==DEBUG== Array: Destructor\n";
		}
		delete[] (ele_);
	}

	unsigned int size() const
	{
		return (ene_);
	}
};

#endif
