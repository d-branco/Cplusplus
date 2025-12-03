/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   main.cpp                             :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/12/02 20:26:16      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/12/03 12:28:36     #########  #########  ###      ###      */
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


// stack: adapts a container to provide stack (LIFO data structure)
int			main(int argc, char **argv)
{
	dprint("Debug mode activated");
	if (argc <2)
	{
		dprint("No argument prodived");
		std::cerr << "Error\n";
		return (EXIT_FAILURE);
	}
	else
	{
		for (int i = 1; argv[i]!=0; ++i)
			{dprint("argv[" << i << "]: " << argv[i]);}
	}
	dprint("");

	
	dprint("");
	dprint("End of main()");
	return (EXIT_SUCCESS);
}
