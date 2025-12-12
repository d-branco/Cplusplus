/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   main.cpp                             :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/12/02 20:26:16      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/12/12 15:42:06     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	dprint("Debug mode activated");
	PmergeMeVec s_v;
	PmergeMeDeq s_d;
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
	std::vector<int> sorted_vec = s_v.run();

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
	bool sorted = true;
	for (size_t i = 0; i < sorted_vec.size() - 1; i++)
	{
		if (sorted_vec[i] > sorted_vec[i + 1])
		{
			std::cerr << "Error: Vector is NOT SORTED correctly!\n";
			sorted = false;
			break;
		}
	}
	if (sorted == true)
	{
		dprint("Vector is correctly sorted");
	}
	std::cout << "After:  ";
	for (unsigned int i = 1; sorted_vec.size() > i - 1; ++i)
	{
		if ((80 - 5 - 8) < (i * (s_v.getNbrLength() + 1)))
		{
			std::cout << " [...]";
			break;
		}
		std::cout << " " << std::setw(s_v.getNbrLength()) << sorted_vec[i - 1];
	}
	std::cout << "\nTime to process " << s_v.getSize()
			  << " elements with std::vector: " << std::setw(3) << seconds
			  << " s  and " << std::setw(6) << nanoseconds << " μs\n";

	gettimeofday(&start_time, NULL);

	// Second algorithm runs here
	std::deque<int> sorted_deq = s_d.run();

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
	sorted = true;
	for (size_t i = 0; i < sorted_deq.size() - 1; i++)
	{
		if (sorted_deq[i] > sorted_deq[i + 1])
		{
			std::cerr << "Error: Deque is NOT SORTED correctly!\n";
			sorted = false;
			break;
		}
	}
	if (sorted == true)
	{
		dprint("Deque is correctly sorted");
	}
	std::cout << "Time to process " << s_v.getSize()
			  << " elements with std::deque:  " << std::setw(3) << seconds
			  << " s  and " << std::setw(6) << nanoseconds << " μs\n";

	dprint("");
	dprint("End of main()");
	return (EXIT_SUCCESS);
}

int initializer(int argc, char **argv, PmergeMeVec &s_v, PmergeMeDeq &s_d)
{
	dprint("Initializing data");

	if (argc < 2)
	{
		dprint("No argument provided");
		std::cerr << "Error\n";
		return (EXIT_FAILURE);
	}

	int max_val = std::atoi(argv[1]);
	s_v.setMax(max_val);
	s_d.setMax(max_val);

	for (int i = 1; argv[i] != 0; ++i)
	{
		int current_val = std::atoi(argv[i]);

		if (0 >= current_val)
		{
			dprint("Number element equal or smaller than zero: " << argv[i]);
			std::cerr << "Error\n";
			return (EXIT_FAILURE);
		}
		if (s_v.getMax() < current_val)
		{
			s_v.setMax(current_val);
			s_d.setMax(current_val);
		}
	}

	s_v.setNbrLength(get_nbr_length(s_v.getMax()));
	s_d.setNbrLength(get_nbr_length(s_d.getMax()));
	dprint("Maximum element: " << s_v.getMax() << " (length: "
							   << get_nbr_length(s_v.getMax()) << ")");

	std::cout << "Before: ";
	for (int i = 1; argv[i] != 0; ++i)
	{
		if ((80 - 5 - 8) < (i * (s_v.getNbrLength() + 1)))
		{
			std::cout << " [...]";
			break;
		}
		std::cout << " " << std::setw(s_v.getNbrLength()) << argv[i];
	}
	std::cout << "\n";
	for (int i = 1; i < argc; ++i)
	{
		s_v.push_back(std::atoi(argv[i]));
		s_d.push_back(std::atoi(argv[i]));
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
