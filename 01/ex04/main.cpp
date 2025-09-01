/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   main.cpp                             :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/09/01 11:38:44      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/09/01 11:50:04     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Input error!\n"
				  << "    usage:\n./better_than_sed.exe  "
				  << "FILE  str_to_find  str_to_replace\n";
		return (EXIT_FAILURE);
	}

	std::ifstream opened_file(argv[1]);

	if (!opened_file.is_open())
	{
		std::cerr << "Error.\nFile failed to open.\n";
		return (EXIT_FAILURE);
	}

	size_t len = 0;
	while (argv[2][len])
	{
		len++;
	}

	std::ofstream output_file((std::string(argv[1]) + ".replace").c_str());
	if (!output_file.is_open())
	{
		std::cerr << "Error: Could not create output file.\n";
		return EXIT_FAILURE;
	}

	char chr;
	bool found = false;
	while (opened_file.get(chr))
	{
		found = false;
		if (chr == argv[2][0])
		{
			// std::cout << "Found the first char: \'" << chr << "\'\n";
			std::streampos reading_pos = opened_file.tellg();

			char		   buffer[len];
			opened_file.read(buffer, len - 1);

			size_t iter = 0;
			while (iter < len - 1)
			{
				if (buffer[iter] != argv[2][iter + 1])
				{
					break;
				}
				iter++;
				if (argv[2][iter + 1] == '\0')
				{
					// std::cout << "    Fount it!\n";
					found = true;
					break;
				}
			}
			std::cout << "\n";
			if (found == false)
			{
				opened_file.clear();
				opened_file.seekg(reading_pos);
			}
		}
		if (found == false)
		{
			output_file << chr;
		}
		else
		{
			output_file << argv[3];
		}
	}

	opened_file.close();
	output_file.close();
	return (EXIT_SUCCESS);
}

/*
afbfda
ZzZ123456789
gshaetj
adsad
asda
da
*/
