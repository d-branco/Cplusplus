/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   main.cpp                             :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/09/16 17:45:30      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/09/16 18:08:21     #########  #########  ###      ###      */
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

	std::cout << "\n";
	Animal *array[6];
	for (size_t k = 0; k < 6; k++)
	{
		if (k % 2 == 0)
		{
			array[k] = new Dog();
		}
		else
		{
			array[k] = new Cat();
		}
	}
	std::cout << "\n";


	std::cout << "\n";
	for (size_t k = 0; k < 6; k++)
	{
		delete array[k];
	}
	std::cout << "\n";


	return (EXIT_SUCCESS);
}
