/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   BitcoinExchange.cpp                  :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/11/30 15:48:54      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/12/21 12:18:38     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

///////////////////////////////////////////////////// Canonical Orthodox Form //
BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	*this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this == &other)
	{
		return (*this);
	}

	this->db_ = other.db_;
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

///////////////////////////////////////////////////////////////////// Getters //
///////////////////////////////////////////////////////////////////// Setters //
/////////////////////////////////////////////////////////////////// Functions //

int BitcoinExchange::input_validation(int			 argc,
									  char		   **argv,
									  std::ifstream &database_file,
									  std::ifstream &input_file,
									  const char	*db_filename)
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

	dprint("input_validation(): DB file: " << db_filename);
	dprint("input_validation(): DB file: Checking if the database exists and "
		   "is readable");
	if (!database_file.good())
	{
		std::cout << "Error: Could not access database " << db_filename << "\n";
		return (EXIT_FAILURE);
	}
	if (get_extension(db_filename) == ".csv")
	{
		dprint("input_validation(): DB file: " << db_filename << " is good");
	}
	else
	{
		dprint("input_validation(): DB file: Extension: "
			   << get_extension(db_filename));
		std::cout << "Error: File does not have the \'.csv\' extention \n";
		return (EXIT_FAILURE);
	}
	dprint("");

	return (EXIT_SUCCESS);
}

std::string BitcoinExchange::get_extension(const char *file_name)
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

void BitcoinExchange::csv_to_map(std::ifstream &database_file)
{
	std::string db_line;

	std::getline(database_file, db_line);
	dprint("csv_to_map(): header skipped: \"" << db_line << "\"");
	while (std::getline(database_file, db_line))
	{
		std::istringstream ss(db_line);
		std::string		   date;
		std::string		   exchange_rate;

		if (std::getline(ss, date, ',') && std::getline(ss, exchange_rate))
		{
			this->db_[date] = exchange_rate;
		}
		else
		{
			dprint("csv_to_map(): invalid line: " << db_line);
		}
	}
	if (this->db_.empty())
	{
		dprint("Database empty!");
		return;
	}
	dprint("csv_to_map(): first element: db["
		   << this->db_.begin()->first << "] = " << this->db_.begin()->second);
	dprint("csv_to_map(): last  element: db["
		   << (this->db_.rbegin())->first
		   << "] = " << (this->db_.rbegin())->second);
	database_file.close();
}

bool BitcoinExchange::check_date_format(std::string date)
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

void BitcoinExchange::parse_line(std::string i_line)
{
	dprint("parseline(): line to parse: \"" << i_line << "\"");
	std::string line = i_line.substr(0, 10);
	dprint("parseline(): date to search: \"" << line << "\"");
	std::map<std::string, std::string>::iterator ite = this->db_.find(line);
	if (ite != this->db_.end())
	{
		dprint("parseline(): Date " << line << " found!");
		calculate_line(ite, i_line);
	}
	else
	{
		std::map<std::string, std::string>::iterator below
			= this->db_.lower_bound(line);

		if (below == this->db_.begin())
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

void BitcoinExchange::calculate_line(
	std::map<std::string, std::string>::iterator ite,
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

	dprint(ite->first << " => " << i_line.substr(13, i_line.size() - 13)
					  << " x " << ite->second);
	double result = historic_value * amount_value;
	std::cout << ite->first << " => " << result << "\n";
}
