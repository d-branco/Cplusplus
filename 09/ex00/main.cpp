/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   main.cpp                             :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/11/30 15:48:40      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/11/30 17:29:53     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

#ifdef DEBUG
# define dprint(msg) std::cout << "==DEBUG== " << msg << "\n"
#else
# define dprint(msg) ((void) 0)
#endif

#define INPUT_FILE argv[1]

std::string get_extension(const char *file_name);

int			main(int argc, char **argv)
{
	dprint("Debug mode activated");
	if (argc == 1)
	{
		std::cout << "Error: Missing database \nUsage: \n  ./btc input.csv\n";
		return (EXIT_FAILURE);
	}
	if (argc > 2)
	{
		std::cout << "Error: Too many arguments \nUsage: \n  ./btc input.csv\n";
		return (EXIT_FAILURE);
	}
	dprint("Input file: " << INPUT_FILE);

	dprint("Checking if file exists and is readable");
	std::ifstream file(INPUT_FILE);
	if (!file.good())
	{
		std::cout << "Error: Could nor access file " << INPUT_FILE << "\n";
		return (EXIT_FAILURE);
	}

	if (get_extension(INPUT_FILE) == ".csv")
	{
		dprint(INPUT_FILE << " is good");
	}
	else
	{
		dprint("Extension: " << get_extension(INPUT_FILE));
		std::cout << "Error: File does not have the \'.csv\' extention \n";
		return (EXIT_FAILURE);
	}

	return (EXIT_SUCCESS);
}

std::string get_extension(const char *file_name)
{
	std::string full_name(file_name);
	size_t		pos = full_name.find_last_of('.');
	if (pos == std::string::npos)
	{
		return ("");
	}
	std::string extension = full_name.substr(pos);
	std::transform(extension.begin(),
				   extension.end(),
				   extension.begin(),
				   ::tolower);
	return (extension);
}