/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   RPN.cpp                              :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/12/02 20:26:00      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/12/21 12:25:14     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include "RPN.hpp"

///////////////////////////////////////////////////// Canonical Orthodox Form //
RPN::RPN()
{
}

RPN::RPN(const RPN &other)
{
	*this = other;
}

RPN &RPN::operator=(const RPN &other)
{
	if (this == &other)
	{
		return (*this);
	}

	return (*this);
}

RPN::~RPN()
{
}

///////////////////////////////////////////////////////////////////// Getters //
///////////////////////////////////////////////////////////////////// Setters //
/////////////////////////////////////////////////////////////////// Functions //

int RPN::run(char *str)
{
	std::stack<int> polish;

	size_t			ite = 0;
	int				nbr;
	while (str[ite])
	{
		dprint("Reading input: " << str[ite]);
		if ((str[ite] >= '0') && (str[ite] <= '9'))
		{
			polish.push(str[ite] - '0');
			dprint("Stack: [" << stack_to_string(polish) << " ]");
		}
		else if ((str[ite] == '+') || (str[ite] == '-') || (str[ite] == '/')
				 || (str[ite] == '*'))
		{
			if (polish.empty())
			{
				std::cerr << "Error\n";
				return (EXIT_FAILURE);
			}
			nbr = (polish.top());
			polish.pop();

			if (polish.empty())
			{
				std::cerr << "Error\n";
				return (EXIT_FAILURE);
			}
			switch (str[ite])
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
		if ((str[ite] != ' ') && (str[ite] != 0))
		{
			std::cerr << "Error\n";
			return (EXIT_FAILURE);
		}
		if (str[ite] != 0)
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

std::string RPN::stack_to_string(std::stack<int> polish)
{
	std::ostringstream oss;
	while (!polish.empty())
	{
		oss << " " << polish.top();
		polish.pop();
	}
	return (oss.str());
}
