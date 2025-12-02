/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   main.cpp                             :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/11/30 15:48:40      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/12/02 18:58:33     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

#ifdef DEBUG
# define dprint(msg) std::cout << "==DEBUG== " << msg << "\n"
#else
# define dprint(msg) ((void) 0)
#endif

#define DB_FILE "../cpp_09/data.csv"

int								   input_validation(int			   argc,
													char		 **argv,
													std::ifstream &database_file,
													std::ifstream &input_file);
std::string						   get_extension(const char *file_name);
std::map<std::string, std::string> csv_to_map(std::ifstream &database_file);
bool							   check_date_format(std::string date);
void parse_line(std::map<std::string, std::string> mapa, std::string line);
void calculate_line(std::map<std::string, std::string>::iterator it,
					std::string									 i_line);

// std::map<Key,T,Compare,Allocator>::lower_bound
// lower_bound is a useful function in the case of searching the earlier date
int	 main(int argc, char **argv)
{
	dprint("Debug mode activated");
	std::ifstream db_file(DB_FILE);
	std::ifstream i_file(argv[1]);
	if (input_validation(argc, argv, i_file, db_file) != 0)
	{
		return (EXIT_FAILURE);
	}

	dprint("");
	dprint("Parsing database into std::map");
	std::map<std::string, std::string> intra = csv_to_map(db_file);

	dprint("");
	dprint("Parsing the input");
	std::string i_line;
	std::getline(i_file, i_line);
	if (check_date_format(i_line))
	{
		dprint("Valid date: " << i_line.substr(0, 10));
		parse_line(intra, i_line);
	}
	else
	{
		dprint("Invalid date");
		dprint("Skipping header");
	}
	dprint("");
	while (std::getline(i_file, i_line))
	{
		dprint("line to parse: \"" << i_line << "\"");
		if (check_date_format(i_line))
		{
			dprint("Valid date: " << i_line.substr(0, 10));
			parse_line(intra, i_line);
		}
		else
		{
			dprint("Invalid date");
			std::cout << "Error: bad input => " << i_line << "\n";
		}
		dprint("");
	}

	// i_file.close();
	dprint("");
	dprint("End of main()");
	return (EXIT_SUCCESS);
}

void parse_line(std::map<std::string, std::string> map_a, std::string i_line)
{
	dprint("parseline(): line to parse: \"" << i_line << "\"");
	std::string line = i_line.substr(0, 10);
	dprint("parseline(): date to search: \"" << line << "\"");
	std::map<std::string, std::string>::iterator ite = map_a.find(line);
	if (ite != map_a.end())
	{
		dprint("parseline(): Date " << line << " found!");
		calculate_line(ite, i_line);
	}
	else
	{
		std::map<std::string, std::string>::iterator below
			= map_a.lower_bound(line);

		if (below == map_a.begin())
		{
			dprint("parseline(): Date "
				   << line << " is before the earliest database date!");
		}
		else
		{
			--below;
			dprint("parseline(): Previous date: "
				   << below->first << " (closest to " << line << ")");
			calculate_line(below, i_line);
		}
	}
}

void calculate_line(std::map<std::string, std::string>::iterator ite,
					std::string									 i_line)
{
	dprint("calculate_line(): map[" << ite->first << "]=" << ite->second << "");

	char  *end_ptr;
	double historic_value = std::strtod(ite->second.c_str(), &end_ptr);
	if (*end_ptr != '\0')
	{
		dprint("calculate_line(): Conversion to double error!");
		std::cout << "Error: bad input => " << i_line << "\n";
		return;
	}
	dprint("calculate_line(): <Double> Value: " << historic_value);
	std::string amount_str	 = i_line.substr(13, i_line.size() - 13);
	double		amount_value = std::strtod(amount_str.c_str(), &end_ptr);
	if (*end_ptr != '\0')
	{
		dprint("calculate_line(): Conversion to double error!");
		std::cout << "Error: bad input => " << i_line << "\n";
		return;
	}
	dprint("calculate_line(): <Double>Amount: " << amount_value);
	if (amount_value < 0)
	{
		std::cout << "Error: not a positive number.\n";
		return;
	}

	if (amount_value > 1000)
	{
		std::cout << "Error: too large a number.\n";
		return;
	}

	// std::cout << "Error: bad input => "<< i_line << "\n";

	dprint(ite->first << " => " << i_line.substr(13, i_line.size() - 13)
					  << " x " << ite->second);
	double result = historic_value * amount_value;
	std::cout << ite->first << " => " << result << "\n";
}

bool check_date_format(std::string date)
{
	if ((date.size() < 13) || (!isdigit(date[0])) || (!isdigit(date[1]))
		|| (!isdigit(date[2])) || (!isdigit(date[3])) || ((date[4]) != '-')
		|| (!isdigit(date[5])) || (!isdigit(date[6])) || ((date[7]) != '-')
		|| (!isdigit(date[8])) || (!isdigit(date[9])) || ((date[10]) != ' ')
		|| ((date[11]) != '|') || ((date[12]) != ' '))
	{
		return (false);
	}

	(void) date;
	return (true);
}

std::map<std::string, std::string> csv_to_map(std::ifstream &database_file)
{
	std::map<std::string, std::string> db;
	std::string						   db_line;

	std::getline(database_file, db_line);
	dprint("csv_to_map(): header skipped: \"" << db_line << "\"");
	while (std::getline(database_file, db_line))
	{
		std::istringstream ss(db_line);
		std::string		   date;
		std::string		   exchange_rate;

		if (std::getline(ss, date, ',') && std::getline(ss, exchange_rate))
		{
			db[date] = exchange_rate;
		}
		else
		{
			dprint("csv_to_map(): invalid line: " << db_line);
		}
	}
	if (db.empty())
	{
		dprint("Database empty!");
		return (db);
	}
	dprint("csv_to_map(): first element: db[" << db.begin()->first
											  << "] = " << db.begin()->second);
	dprint("csv_to_map(): last  element: db["
		   << (db.rbegin())->first << "] = " << (db.rbegin())->second);
	database_file.close();
	return (db);
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
	dprint("input_validation(): Input file: " << argv[1] << " is good");

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
