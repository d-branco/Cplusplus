/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   main.cpp                             :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/12/02 20:26:16      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/12/02 21:39:17     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>

#ifdef DEBUG
# define dprint(msg) std::cout << "==DEBUG== " << msg << "\n"
#else
# define dprint(msg) ((void) 0)
#endif

std::string stack_to_string(std::stack<char> polish);

// stack: adapts a container to provide stack (LIFO data structure)
int			main(int, char **argv)
{
	dprint("Debug mode activated");
	dprint("");

	std::stack<char> polish;

	size_t			 ite = 1;
	// int				 nbr;
	while (argv[ite])
	{
		dprint("argv[i]: " << argv[ite]);
		if (((argv[ite][0] >= '0') && (argv[ite][0] <= '9'))
			|| (argv[ite][0] == '+') || (argv[ite][0] == '-')
			|| (argv[ite][0] == '/') || (argv[ite][0] == '*'))
		{
			polish.push(argv[ite][0]);
			// dprint("nbr: " << nbr);
			// nbr = atoi(argv[ite]);
		}
		++ite;
	}

	dprint("Stack: [" << stack_to_string(polish) << " ]");

	dprint("");
	dprint("End of main()");
	return (EXIT_SUCCESS);
}

std::string stack_to_string(std::stack<char> polish)
{
	std::ostringstream oss;
	while (!polish.empty())
	{
		oss << " " << polish.top();
		polish.pop();
	}
	return (oss.str());
}
