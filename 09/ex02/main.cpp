/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   main.cpp                             :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/12/02 20:26:16      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/12/11 16:51:47     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	dprint("Debug mode activated");
	t_vec s_v;
	t_deq s_d;
	if (initializer(argc, argv, s_v, s_d) != EXIT_SUCCESS)
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
	s_v.vicky = merge_intertion_vec(s_v);

	gettimeofday(&end_time, NULL);

	long seconds	 = end_time.tv_sec - start_time.tv_sec;
	long nanoseconds = end_time.tv_usec - start_time.tv_usec;
	if (nanoseconds < 0)
	{
		seconds--;
		nanoseconds += 1000000;
	}
	duration = seconds * 1000000 + nanoseconds;
	(void) duration;
	dprint("Time duration: " << duration << " nanoseconds");

	std::cout << "After:  ";
	for (unsigned int i = 1; s_v.vicky.size() > i - 1; ++i)
	{
		if ((80 - 8 - 6) < (i * (s_v.nbr_length + 1)))
		{
			std::cout << " [...]";
			break;
		}
		std::cout << " " << std::setw(s_v.nbr_length) << s_v.vicky[i - 1];
	}
	std::cout << "\nTime to process " << s_v.array_size
			  << " elements with std::vector: " << std::setw(3) << seconds
			  << " s  and " << std::setw(6) << nanoseconds << " μs\n";

	gettimeofday(&start_time, NULL);

	// Second algorithm runs here
	s_d.duke = merge_intertion_deq(s_d);

	gettimeofday(&end_time, NULL);

	seconds		= end_time.tv_sec - start_time.tv_sec;
	nanoseconds = end_time.tv_usec - start_time.tv_usec;
	if (nanoseconds < 0)
	{
		seconds--;
		nanoseconds += 1000000;
	}
	duration = seconds * 1000000 + nanoseconds;
	dprint("Time duration: " << duration << " nanoseconds");

	std::cout << "Time to process " << s_v.array_size
			  << " elements with std::deque:  " << std::setw(3) << seconds
			  << " s  and " << std::setw(6) << nanoseconds << " μs\n";

	dprint("");
	dprint("End of main()");
	return (EXIT_SUCCESS);
}

int initializer(int argc, char **argv, t_vec &s_v, t_deq &s_d)
{
	dprint("Initializing data");

	if (argc < 2)
	{
		dprint("No argument provided");
		std::cerr << "Error\n";
		return (EXIT_FAILURE);
	}

	s_v.maximum_value = atoi(argv[1]);
	s_d.maximum_value = atoi(argv[1]);
	s_v.array_size	  = 0;
	s_d.array_size	  = 0;

	for (int i = 1; argv[i] != 0; ++i)
	{
		int current_val = atoi(argv[i]);

		if (0 >= current_val)
		{
			dprint("Number element equal or smaller than zero: " << argv[i]);
			std::cerr << "Error\n";
			return (EXIT_FAILURE);
		}
		if (s_v.maximum_value < current_val)
		{
			s_v.maximum_value = current_val;
			s_d.maximum_value = current_val;
		}
		s_v.array_size++;
	}

	s_v.nbr_length = get_nbr_length(s_v.maximum_value);
	s_d.nbr_length = get_nbr_length(s_v.maximum_value);
	dprint("Maximum element: " << s_v.maximum_value << " (length: "
							   << get_nbr_length(s_v.maximum_value) << ")");

	std::cout << "Before: ";
	for (int i = 1; argv[i] != 0; ++i)
	{
		if ((80 - 8 - 6) < (i * (s_v.nbr_length + 1)))
		{
			std::cout << " [...]";
			break;
		}
		std::cout << " " << std::setw(s_v.nbr_length) << argv[i];
	}
	std::cout << "\n";
	for (int i = 1; i < argc; ++i)
	{
		s_v.vicky.push_back(std::atoi(argv[i]));
		s_d.duke.push_back(std::atoi(argv[i]));
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
