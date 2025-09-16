/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   main.cpp                             :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/09/16 17:20:42      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/09/16 17:25:31     #########  #########  ###      ###      */
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
	Animal *array[7];
	for (int k = 0; k < 6; k++)
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
	for (int k = 0; k < 6; k++)
	{
		delete array[k];
	}


	return (EXIT_SUCCESS);
}
