/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   main.cpp                             :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/09/16 12:14:14      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/09/16 12:51:58     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

// Remember to make "the most complete tests"!

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include <cstdlib>
#include <iostream>
#include <string>

int main()
{
	Dog canine("Dog");
	Cat feline("Cat");
	Dog canis(canine);
	Cat felix(feline);

	return (EXIT_SUCCESS);
}
