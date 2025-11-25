/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   main.cpp                             :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/11/25 10:54:17      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/11/25 14:09:12     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include <cstdlib>

#ifndef DEBUG
# define DEBUG false
#endif

#include "Data.hpp"
#include "Serializer.hpp"

int main(void)
{
	Data *message		 = new Data();
	message->secret_code = 42;
	std::cout << "Old pointer (at " << &message << ") points to:\n  " << message
			  << "    (secret code: " << message->secret_code << ")\n";

	uintptr_t duo = Serializer::serialize(message);
	std::cout << "Unsigned integer value: \n  0x" << std::hex << duo << std::dec
			  << "\n";

	Data *response = Serializer::deserialize(duo);
	std::cout << "New pointer (at " << &response << ") points to:\n  "
			  << response << "    (secret code: " << response->secret_code
			  << ")\n";

	delete (message);
	return (EXIT_SUCCESS);
}