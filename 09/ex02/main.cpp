/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   main.cpp                             :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/12/02 20:26:16      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/12/10 21:39:28     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	dprint("Debug mode activated");
	s_init s_i;
	if (initializer(argc, argv, s_i) != EXIT_SUCCESS)
	{
		return (EXIT_FAILURE);
	}
	struct timeval start_time;
	struct timeval end_time;
	long		   duration = 0;
	gettimeofday(&start_time, NULL);
	gettimeofday(&end_time, NULL);

	gettimeofday(&start_time, NULL);

	// First algorithm runs here
	merge_intertion_vec(s_i);
	// s_i.vicky = merge_intertion_vec(s_i.vicky); // ideally

	gettimeofday(&end_time, NULL);

	long seconds	  = end_time.tv_sec - start_time.tv_sec;
	long microseconds = end_time.tv_usec - start_time.tv_usec;
	duration		  = seconds * 1000000 + microseconds;
	dprint("Time duration: " << duration << " microseconds");

	std::cout << "After:  ";
	for (unsigned int i = 1; s_i.vicky.size() > i - 1; ++i)
	{
		if ((80 - 8 - 6) < (i * (s_i.nbr_length + 1)))
		{
			std::cout << " [...]";
			break;
		}
		std::cout << " " << std::setw(s_i.nbr_length) << s_i.vicky[i - 1];
	}
	std::cout << "\nTime to process " << s_i.array_size
			  << " elements with std::vector: " << duration << " μs\n";

	gettimeofday(&start_time, NULL);

	// Second algorithm runs here

	gettimeofday(&end_time, NULL);

	seconds		 = end_time.tv_sec - start_time.tv_sec;
	microseconds = end_time.tv_usec - start_time.tv_usec;
	duration	 = seconds * 1000000 + microseconds;
	dprint("Time duration: " << duration << " microseconds");

	std::cout << "Time to process " << s_i.array_size
			  << " elements with std::deque:  " << duration << " μs\n";

	dprint("");
	dprint("End of main()");
	return (EXIT_SUCCESS);
}

int initializer(int argc, char **argv, t_init &s_i)
{
	dprint("Initializing data");

	if (argc < 2)
	{
		dprint("No argument provided");
		std::cerr << "Error\n";
		return (EXIT_FAILURE);
	}

	s_i.maximum_value = atoi(argv[1]);
	s_i.array_size	  = 0;

	for (int i = 1; argv[i] != 0; ++i)
	{
		int current_val = atoi(argv[i]);

		if (0 >= current_val)
		{
			dprint("Number element equal or smaller than zero: " << argv[i]);
			std::cerr << "Error\n";
			return (EXIT_FAILURE);
		}
		if (s_i.maximum_value < current_val)
		{
			s_i.maximum_value = current_val;
		}
		s_i.array_size++;
	}

	s_i.nbr_length = get_nbr_length(s_i.maximum_value);
	dprint("Maximum element: " << s_i.maximum_value << " (length: "
							   << get_nbr_length(s_i.maximum_value) << ")");

	std::cout << "Before: ";
	for (int i = 1; argv[i] != 0; ++i)
	{
		if ((80 - 8 - 6) < (i * (s_i.nbr_length + 1)))
		{
			std::cout << " [...]";
			break;
		}
		std::cout << " " << std::setw(s_i.nbr_length) << argv[i];
	}
	std::cout << "\n";
	for (int i = 1; i < argc; ++i)
	{
		s_i.vicky.push_back(std::atoi(argv[i]));
		s_i.duke.push_back(std::atoi(argv[i]));
	}

	dprint("Initialization successful");
	dprint("");
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
	if (nbr == 0)
	{
		return 1;
	}
	while (nbr > 0)
	{
		nbr /= 10;
		len++;
	}

	return (len);
}
