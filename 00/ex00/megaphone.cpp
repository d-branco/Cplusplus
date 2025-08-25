/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 16:00:05 by abessa-m          #+#    #+#             */
/*   Updated: 2025/08/25 07:53:58 by abessa-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
