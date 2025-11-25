/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   main.cpp                             :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/11/25 10:54:17      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/11/25 12:50:04     #########  #########  ###      ###      */
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

	uintptr_t duo  = Serializer::serialize(message);
	Data *response = Serializer::deserialize(duo);
	(void) response;

	delete (message);
	return (EXIT_SUCCESS);
}