/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   main.cpp                             :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/11/30 15:48:40      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/12/21 12:17:32     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

// dprint is now in BitcoinExchange.hpp
// #ifdef DEBUG
// # define dprint(msg) std::cout << "==DEBUG== " << msg << "\n"
// #else
// # define dprint(msg) ((void) 0)
// #endif

#define DB_FILE "../cpp_09/data.csv"

// std::map<Key,T,Compare,Allocator>::lower_bound
// lower_bound is a useful function in the case of searching the earlier date
int main(int argc, char **argv)
{
	dprint("Debug mode activated");
	std::ifstream	db_file(DB_FILE);
	std::ifstream	i_file(argv[1]);

	BitcoinExchange btc;

	if (btc.input_validation(argc, argv, db_file, i_file, DB_FILE) != 0)
	{
		return (EXIT_FAILURE);
	}

	dprint("");
	dprint("Parsing database into std::map");
	btc.csv_to_map(db_file);

	dprint("");
	dprint("Parsing the input");
	std::string i_line;
	std::getline(i_file, i_line);
	if (btc.check_date_format(i_line))
	{
		dprint("Valid date: " << i_line.substr(0, 10));
		btc.parse_line(i_line);
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
		if (btc.check_date_format(i_line))
		{
			dprint("Valid date: " << i_line.substr(0, 10));
			btc.parse_line(i_line);
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
