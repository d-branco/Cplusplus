/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   main.cpp                             :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/12/02 20:26:16      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/12/03 16:58:34     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include <string>

#ifdef DEBUG
# define dprint(msg) std::cout << "==DEBUG== " << msg << "\n"
#else
# define dprint(msg) ((void) 0)
#endif

int get_nbr_length(int nbr);

// stack: adapts a container to provide stack (LIFO data structure)
int main(int argc, char **argv)
{
	dprint("Debug mode activated");
	if (argc < 2)
	{
		dprint("No argument prodived");
		std::cerr << "Error\n";
		return (EXIT_FAILURE);
	}
	int maximum = atol(argv[1]);
	int minimum = atol(argv[1]);
	for (int i = 1; argv[i] != 0; ++i)
	{
		dprint("argv[" << i << "]: " << argv[i]);
		if (maximum < atol(argv[i]))
		{
			maximum = atol(argv[i]);
		}
		else if (minimum > atol(argv[i]))
		{
			minimum = atol(argv[i]);
		}
	}
	dprint("Maximum element: " << maximum
							   << " length: " << get_nbr_length(maximum));
	dprint("Minimum element: " << minimum
							   << " length: " << get_nbr_length(minimum));

	dprint("");

	dprint("");
	dprint("End of main()");
	return (EXIT_SUCCESS);
}

int get_nbr_length(int nbr)
{
	int len = 0;
	if (nbr < 0)
	{
		len++;
		nbr = -nbr;
	}
	while (nbr > 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}
