/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   Base.cpp                             :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/11/24 18:47:35      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/11/25 08:28:32     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

///////////////////////////////////////////////////// Canonical Orthodox Form //
Base::Base()
{
	if (DEBUG)
	{
		std::cout << "==DEBUG== Base: Default Constructor\n";
	}
}

// Base::Base(const Base &other)
// {
// 	if (DEBUG)
// 	{
// 		std::cout << "==DEBUG== Base: Copy Constructor\n";
// 	}
// 	*this = other;
// }

// Base &Base::operator=(const Base &other)
// {
// 	if (DEBUG)
// 	{
// 		std::cout << "==DEBUG== Base: Copy Operator Constructor\n";
// 	}
// 	if (this == &other)
// 	{
// 		return (*this);
// 	}

// 	return (*this);
// }

Base::~Base()
{
	if (DEBUG)
	{
		std::cout << "==DEBUG== Base: Destructor\n";
	}
}

///////////////////////////////////////////////////////////////////// Getters //
///////////////////////////////////////////////////////////////////// Setters //
/////////////////////////////////////////////////////////////////// Functions //
Base *generate(void)
{
	int rando = (rand() % 3);

	if (rando == 0)
	{
		if (DEBUG)
		{
			std::cout << "==DEBUG== Base: generate: A\n";
		}
		return (new A());
	}
	else if (rando == 1)
	{
		if (DEBUG)
		{
			std::cout << "==DEBUG== Base: generate: B\n";
		}
		return (new B());
	}
	else
	{
		if (DEBUG)
		{
			std::cout << "==DEBUG== Base: generate: C\n";
		}
		return (new C());
	}
}

void identify(Base *p)
{
	if (dynamic_cast<A *>(p))
	{
		std::cout << "Object pointed: A" << "\n";
	}
	else if (dynamic_cast<B *>(p))
	{
		std::cout << "Object pointed: B" << "\n";
	}
	else if (dynamic_cast<C *>(p))
	{
		std::cout << "Object pointed: C" << "\n";
	}
}

// Using a pointer inside this function is forbidden
void identify(Base &p)
{
	try
	{
		(void) dynamic_cast<A &>(p);
		std::cout << "Object referenced: A" << "\n";

		return;
	}
	catch (std::exception &e)
	{
		if (DEBUG)
		{
			std::cout << "==DEBUG== Base: identify: not A\n";
		}
	}
	try
	{
		(void) dynamic_cast<B &>(p);
		std::cout << "Object referenced: B" << "\n";

		return;
	}
	catch (std::exception &e)
	{
		if (DEBUG)
		{
			std::cout << "==DEBUG== Base: identify: not B\n";
		}
	}
	try
	{
		(void) dynamic_cast<C &>(p);
		std::cout << "Object referenced: C" << "\n";

		return;
	}
	catch (std::exception &e)
	{
		if (DEBUG)
		{
			std::cout << "==DEBUG== Base: identify: not C\n";
		}
	}
}
