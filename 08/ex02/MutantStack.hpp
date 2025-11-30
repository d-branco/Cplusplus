/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   MutantStack.hpp                      :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/11/30 12:19:21      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/11/30 14:48:14     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#ifndef DEBUG
# define DEBUG false
#endif

#include <iostream>
#include <stack>

template <class T> class MutantStack : public std::stack<T>
{
  private:
  public:
	///////////////////////////////////////////////// Canonical Orthodox Form //
	MutantStack() : std::stack<T>()
	{
		if (DEBUG)
		{
			std::cout << "==DEBUG== MutantStack: Default Consctructor\n";
		}
	}

	MutantStack(const MutantStack &other) : std::stack<T>(other)
	{
		if (DEBUG)
		{
			std::cout << "==DEBUG== MutantStack:  Copy Consctructor\n";
		}
	}

	MutantStack &operator=(const MutantStack &other)
	{
		if (DEBUG)
		{
			std::cout << "==DEBUG== MutantStack: Copy Operator Consctructor\n";
		}
		if (this != &other)
		{
			std::stack<T>::operator=(other);
		}
		return *this;
	}

	virtual ~MutantStack()
	{
		if (DEBUG)
		{
			std::cout << "==DEBUG== MutantStack: Default Destructor\n";
		}
	}

	//////////////////////////////////////////////////////////////// Iterator //
	//     Creates a new alias called 'iterator'
	// that takes the place of the iterator of the container.
	typedef typename std::stack<T>::container_type::iterator iterator;

	/////////////////////////////////////////////////////////////// Functions //
	// Access to 'c' - from std::stack
	iterator												 begin()
	{
		if (DEBUG)
		{
			std::cout << "==DEBUG== MutantStack: begin()\n";
		}
		return (this->c.begin());
	}

	iterator end()
	{
		if (DEBUG)
		{
			std::cout << "==DEBUG== MutantStack: end()\n";
		}
		return (this->c.end());
	}
};

#endif
