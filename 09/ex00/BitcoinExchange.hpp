/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   BitcoinExchange.hpp                  :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/11/30 15:48:54      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/12/21 12:18:38     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

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

class BitcoinExchange
{
  private:
	std::map<std::string, std::string> db_;

  public:
	///////////////////////////////////////////////// Canonical Orthodox Form //
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);
	~BitcoinExchange();

	///////////////////////////////////////////////////////////////// Getters //
	///////////////////////////////////////////////////////////////// Setters //
	/////////////////////////////////////////////////////////////// Functions //
	int			input_validation(int			argc,
								 char		  **argv,
								 std::ifstream &database_file,
								 std::ifstream &input_file,
								 const char	   *db_filename);
	std::string get_extension(const char *file_name);
	void		csv_to_map(std::ifstream &database_file);
	bool		check_date_format(std::string date);
	void		parse_line(std::string line);
	void		calculate_line(
					std::map<std::string, std::string>::iterator	it,
					std::string										i_line);
};

#endif
