/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   main.cpp                             :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/12/02 20:26:16      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/12/08 14:32:13     #########  #########  ###      ###      */
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

std::string stack_to_string(std::stack<int> polish);

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

	std::stack<int> polish;

	size_t			ite = 0;
	int				nbr;
	while (argv[1][ite])
	{
		dprint("Reading input: " << argv[1][ite]);
		if ((argv[1][ite] >= '0') && (argv[1][ite] <= '9'))
		{
			polish.push(argv[1][ite] - '0');
			dprint("Stack: [" << stack_to_string(polish) << " ]");
			// dprint("nbr: " << nbbr);
			// nbr = atoi(argv[ite]);
		}
		else if ((argv[1][ite] == '+') || (argv[1][ite] == '-')
				 || (argv[1][ite] == '/') || (argv[1][ite] == '*'))
		{
			nbr = (polish.top());
			polish.pop();
			// dprint("nbr = " << nbr);
			// dprint("Stack: [" << stack_to_string(polish) << " ]");
			
			switch (argv[1][ite])
			{
				case '+':
				{
					nbr += (polish.top());
					break;
				}
				case '-':
				{
					nbr = (polish.top()) - nbr;
					break;
				}
				case '/':
				{
					nbr = (polish.top()) / nbr;
					break;
				}
				case '*':
				{
					nbr = (polish.top()) * nbr;
					break;
				}
				default:
				{
					dprint("Unreachable \'swich case default\'");
				}
			}

			polish.pop();
			dprint("Stack: [" << stack_to_string(polish) << " ]");
			dprint("nbr = " << nbr);
			polish.push(nbr);
			dprint("Stack: [" << stack_to_string(polish) << " ]");
			dprint("Result: " << polish.top());
			dprint("");
		}
		else
		{
			std::cerr << "Error\n";
			return (EXIT_FAILURE);
		}
		++ite;
		if ((argv[1][ite] != ' ') && (argv[1][ite] != 0))
		{
			std::cerr << "Error\n";
			return (EXIT_FAILURE);
		}
		if (argv[1][ite] != 0)
		{
			++ite;
		}
	}

	dprint("Stack: [" << stack_to_string(polish) << " ]");

	std::cout << polish.top() << "\n";
	dprint("");
	dprint("End of main()");
	return (EXIT_SUCCESS);
}

std::string stack_to_string(std::stack<int> polish)
{
	std::ostringstream oss;
	while (!polish.empty())
	{
		oss << " " << polish.top();
		polish.pop();
	}
	return (oss.str());
}
