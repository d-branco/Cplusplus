/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   main.cpp                             :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/11/24 18:46:28      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/11/25 12:31:50     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>

#include "Base.hpp"

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main(void)
{
	std::srand(std::time(0));

	Base *alpha = generate();
	identify(alpha);
	identify(*alpha);
	delete (alpha);
	
	return (EXIT_SUCCESS);
}
