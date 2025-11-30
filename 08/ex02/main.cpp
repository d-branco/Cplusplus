/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   main.cpp                             :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/11/30 12:20:41      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/11/30 14:54:37     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include "MutantStack.hpp"

#include <cstdlib>
#include <list>

int main(void)
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "Top: " << mstack.top() << "\n";
	std::cout << "Top: " << mstack.top() << "\n";
	mstack.pop();
	std::cout << "Size: " << mstack.size() << "\n\n";

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(225);
	mstack.push(0);
	MutantStack<int>::iterator it  = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	std::cout << "From begin() to end():\n";
	while (it != ite)
	{
		std::cout << *it << "\n";
		++it;
	}
	std::stack<int> s(mstack);

	std::cout << "\nOnce more, with list\n";

	std::list<int> mlist;
	mlist.push_back(5);
	mlist.push_back(17);
	std::cout << "Top: " << mlist.front() << "\n";
	std::cout << "Top: " << mlist.front() << "\n";
	mlist.front();
	std::cout << "Size: " << mlist.size() << "\n\n";

	mlist.push_back(3);
	mlist.push_back(5);
	mlist.push_back(737);
	mlist.push_back(225);
	mlist.push_back(0);
	std::list<int>::iterator it2  = mlist.begin();
	std::list<int>::iterator ite2 = mlist.end();
	++it2;
	--it2;
	std::cout << "From begin() to end():\n";
	while (it2 != ite2)
	{
		std::cout << *it2 << "\n";
		++it2;
	}
	std::list<int> t(mlist);

	return (EXIT_SUCCESS);
}

// MutantStack<int> mstack;
// mstack.push(5);
// mstack.push(17);
// std::cout << mstack.top() << std::endl;
// mstack.pop();
// std::cout << mstack.size() << std::endl;
// mstack.push(3);
// mstack.push(5);
// mstack.push(737);
// //[...]
// mstack.push(0);
// MutantStack<int>::iterator it = mstack.begin();
// MutantStack<int>::iterator ite = mstack.end();
// ++it;
// --it;
// while (it != ite)
// {
// std::cout << *it << std::endl;
// ++it;
// }
// std::stack<int> s(mstack);
// return 0;
