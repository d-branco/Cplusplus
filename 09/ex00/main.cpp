/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   main.cpp                             :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/11/30 15:48:40      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/12/01 14:30:27     #########  #########  ###      ###      */
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

#define DB_FILE "../cpp_09/data.csv"

int			input_validation(int			argc,
							 char		  **argv,
							 std::ifstream &database_file,
							 std::ifstream &input_file);
std::string get_extension(const char *file_name);

int			main(int argc, char **argv)
{
	dprint("Debug mode activated");
	std::ifstream db_file(DB_FILE);
	std::ifstream i_file(argv[1]);
	if (input_validation(argc, argv, i_file, db_file) != 0)
	{
		return (EXIT_FAILURE);
	}

	dprint("");
	dprint("End of main()");
	return (EXIT_SUCCESS);
}

int input_validation(int			argc,
					 char		  **argv,
					 std::ifstream &database_file,
					 std::ifstream &input_file)
{
	dprint("");
	dprint("input_validation(): Checking number of arguments");
	if (argc == 1)
	{
		std::cout << "Error: Missing input \nUsage: \n  ./btc input.txt\n";
		return (EXIT_FAILURE);
	}
	if (argc > 2)
	{
		std::cout << "Error: Too many arguments \nUsage: \n  ./btc input.txt\n";
		return (EXIT_FAILURE);
	}
	dprint("input_validation(): Input file: " << argv[1]);

	dprint("input_validation(): Input file: Checking if the input file exists "
		   "and is "
		   "readable");
	if (!input_file.good())
	{
		std::cout << "Error: Could not access file " << argv[1] << "\n";
		return (EXIT_FAILURE);
	}
	else
	{
		dprint("input_validation(): Input file: " << argv[1] << " is good");
	}

	dprint("input_validation(): DB file: " << DB_FILE);
	dprint("input_validation(): DB file: Checking if the database exists and "
		   "is readable");
	if (!database_file.good())
	{
		std::cout << "Error: Could not access database " << DB_FILE << "\n";
		return (EXIT_FAILURE);
	}
	if (get_extension(DB_FILE) == ".csv")
	{
		dprint("input_validation(): DB file: " << DB_FILE << " is good");
	}
	else
	{
		dprint("input_validation(): DB file: Extension: "
			   << get_extension(DB_FILE));
		std::cout << "Error: File does not have the \'.csv\' extention \n";
		return (EXIT_FAILURE);
	}
	dprint("");

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
