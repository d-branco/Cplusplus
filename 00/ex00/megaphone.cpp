/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   megaphone.cpp                        :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/08/25 08:07:00      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/08/25 18:56:05     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include <cctype>
#include <cstdlib>
#include <iostream>

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return (EXIT_SUCCESS);
	}

	int chr;
	int arg = 1;
	while (arg < argc)
	{
		chr = 0;
		while (argv[arg][chr] != '\0')
		{
			std::cout << (char) std::toupper(argv[arg][chr]);
			chr++;
		}
		arg++;
	}
	std::cout << '\n';
	return (EXIT_SUCCESS);
}
