/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   main.cpp                             :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/12/02 20:26:16      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/12/04 13:05:55     #########  #########  ###      ###      */
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

typedef struct s_init t_init;

int					  get_nbr_length(int nbr);
void				  get_duration(t_init &s_i);

typedef struct s_init
{
	int			   maximum_value;
	int			   array_size;
	int			   nbr_length;
	struct timeval start_time;
	struct timeval end_time;
	long		   duration;
} t_init;

int initializer(int argc, char **argv, t_init &s_i);

int main(int argc, char **argv)
{
	dprint("Debug mode activated");

	s_init s_i;
	if (initializer(argc, argv, s_i) != EXIT_SUCCESS)
	{
		return (EXIT_FAILURE);
	}
	gettimeofday(&s_i.start_time, NULL);

	// First algorithm runs here

	gettimeofday(&s_i.end_time, NULL);
	get_duration(s_i);

	std::cout << "After " << "\n";
	std::cout << "Time to process a range of " << s_i.array_size
			  << " elements with std::[..] : " << s_i.duration << " μs\n";

	gettimeofday(&s_i.start_time, NULL);

	// Second algorithm runs here

	gettimeofday(&s_i.end_time, NULL);
	get_duration(s_i);

	std::cout << "Time to process a range of " << s_i.array_size
			  << " elements with std::[..] : " << s_i.duration << " μs\n";

	dprint("");
	dprint("End of main()");
	return (EXIT_SUCCESS);
}

void get_duration(t_init &s_i)
{
	long seconds	  = s_i.end_time.tv_sec - s_i.start_time.tv_sec;
	long microseconds = s_i.end_time.tv_usec - s_i.start_time.tv_usec;
	s_i.duration	  = seconds * 1000000 + microseconds;
	dprint("Time duration: " << s_i.duration << " microseconds");
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
			std::cout << "Error\n";
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

	gettimeofday(&s_i.start_time, NULL);
	gettimeofday(&s_i.end_time, NULL);
	s_i.duration = 0;

	std::cout << "Before ";
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
