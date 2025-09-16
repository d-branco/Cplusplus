/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   main.cpp                             :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/09/16 14:29:46      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/09/16 14:43:57     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

// Remember to make "the most complete tests"!

#include "Animal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#include <cstdlib>
#include <iostream>
#include <string>

int main()
{
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	delete j; // should not create a leak
	delete i;

	return (EXIT_SUCCESS);
}
