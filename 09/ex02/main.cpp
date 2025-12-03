/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   main.cpp                             :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/12/02 20:26:16      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/12/03 21:27:49     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>
#include <sys/time.h>

#ifdef DEBUG
# define dprint(msg) std::cout << "==DEBUG== " << msg << "\n"
#else
# define dprint(msg) ((void) 0)
#endif

int get_nbr_length(int nbr);

// std::array
// std::vector
// std::list
// std::deque
// std::string -> since its a container, it is technically a valid option
int main(int argc, char **argv)
{
	dprint("Debug mode activated");
	if (argc < 2)
	{
		dprint("No argument provided");
		std::cerr << "Error\n";
		return (EXIT_FAILURE);
	}
	int maximum	   = atoi(argv[1]);
	int array_size = 0;
	for (int i = 1; argv[i] != 0; ++i)
	{
		// dprint("argv[" << i << "]: " << argv[i]);
		if (0 >= atoi(argv[i]))
		{
			dprint("Number elemente equal or smaller than zero");
			std::cout << "Error\n";
			return (EXIT_FAILURE);
		}
		if (maximum < atoi(argv[i]))
		{
			maximum = atoi(argv[i]);
		}
		array_size++;
	}
	int nbr_length = get_nbr_length(maximum);
	dprint("Number length: " << nbr_length << " (" << maximum << ")");
	dprint("Maximum element: " << maximum
							   << " length: " << get_nbr_length(maximum));
	std::cout << "Before ";
	for (int i = 1; argv[i] != 0; ++i)
	{
		if ((80 - 8 - 6) < (i * (nbr_length + 1)))
		{
			std::cout << " [...]";
			break;
		}
		std::cout << " " << std::setw(nbr_length) << argv[i];
	}
	std::cout << "\n";
	dprint("");

	struct timeval start;
	struct timeval end;
	gettimeofday(&start, NULL);

	// Algorithm runs here

	gettimeofday(&end, NULL);
	long seconds	  = end.tv_sec - start.tv_sec;
	long microseconds = end.tv_usec - start.tv_usec;
	long elapsed	  = seconds * 1000000 + microseconds;
	dprint("Time: " << elapsed << " microseconds");

	std::cout << "After " << "\n";
	std::cout << "Time to process a range of " << array_size
			  << " elements with std::[..] : " << elapsed << " μs\n";
	std::cout << "Time to process a range of " << array_size
			  << " elements with std::[..] : " << elapsed << " μs\n";

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
