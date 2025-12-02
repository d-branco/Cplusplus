/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   main.cpp                             :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/12/02 20:26:16      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/12/02 22:27:30     #########  #########  ###      ###      */
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
int			main(int argc, char **argv)
{
	dprint("Debug mode activated");
	if (argc != 2)
	{
		dprint("argc: " << argc);
		std::cerr << "Error\n";
		return (EXIT_FAILURE);
	}
	dprint("");

	std::stack<char> polish;

	size_t			 ite = 0;
	// int				 nbr;
	while (argv[1][ite])
	{
		dprint("argv[1][" << ite << "]: " << argv[1][ite]);
		if (((argv[1][ite] >= '0') && (argv[1][ite] <= '9'))
			|| (argv[1][ite] == '+') || (argv[1][ite] == '-')
			|| (argv[1][ite] == '/') || (argv[1][ite] == '*'))
		{
			polish.push(argv[1][ite]);
			// dprint("nbr: " << nbbr);
			// nbr = atoi(argv[ite]);
		}
		else
		{
			std::cerr << "Error\n";
			return (EXIT_FAILURE);
		}
		++ite;
		if (argv[1][ite] != 0)
		{
			++ite;
		}
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
