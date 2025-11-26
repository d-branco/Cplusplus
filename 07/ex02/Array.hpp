/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   Array.hpp                            :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/11/25 19:25:39      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/11/25 22:24:54     #########  #########  ###      ###      */
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

	Array(const Array &other) : ele_(0), ene_(0)
	{
		if (DEBUG)
		{
			std::cout << "==DEBUG== Array: Copy Constructor\n";
		}
		if (other.ene_ > 0)
		{
			this->ele_ = new T[other.ene_]();
			this->ene_ = other.ene_;
			for (unsigned int ite = 0; ite < this->ene_; ite++)
			{
				this->ele_[ite] = other.ele_[ite];
			}
		}
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

		if (this->ele_)
		{
			delete[] this->ele_;
		}
		this->ene_ = other.ene_;
		if (this->ene_ > 0)
		{
			this->ele_ = new T[this->ene_]();
			for (unsigned int ite = 0; ite < this->ene_; ite++)
			{
				this->ele_[ite] = other.ele_[ite];
			}
		}
		else
		{
			this->ele_ = 0;
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

	T &operator[](unsigned int ite)
	{
		if ((DEBUG) && (ite == 0))
		{
			std::cout << "==DEBUG== Array: operator[0]\n";
		}
		if (ite >= this->ene_)
		{
			if (DEBUG)
			{
				std::cout << "==DEBUG== Array: operator[]: out of bound\n";
			}
			throw std::exception();
		}
		return (this->ele_[ite]);
	}

	const T &operator[](unsigned int ite) const
	{
		if ((DEBUG) && (ite == 0))
		{
			std::cout << "==DEBUG== Array: const operator[0]\n";
		}
		if (ite >= this->ene_)
		{
			if (DEBUG)
			{
				std::cout << "==DEBUG== Array: const operator[]: out of "
							 "bound\n";
			}
			throw std::exception();
		}
		return (this->ele_[ite]);
	}
};

#endif
