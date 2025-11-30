/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   MutantStack.hpp                      :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/11/30 12:19:21      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/11/30 13:36:41     #########  #########  ###      ###      */
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

	///////////////////////////////////////////////////////////////// Getters //
	///////////////////////////////////////////////////////////////// Setters //
	/////////////////////////////////////////////////////////////// Functions //
};

#endif
