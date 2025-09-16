/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   main.cpp                             :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/09/16 14:02:33      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/09/16 14:03:37     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

// Remember to make "the most complete tests"!

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#include <cstdlib>
#include <iostream>
#include <string>

int main()
{
	// Dog canine("Dog");
	// Cat feline("Cat");
	// Dog canis(canine);
	// Cat felix(feline);
	// std::cout << "\n";

	const Animal *meta = new Animal();
	const Animal *j	   = new Dog();
	const Animal *i	   = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); // will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete (meta);
	delete (i);
	delete (j);

	// std::cout << "\n";
	// const WrongAnimal *alem = new WrongAnimal();
	// const WrongAnimal *k	= new WrongCat();
	// const WrongCat	  *l	= new WrongCat();
	// std::cout << k->getType() << " " << std::endl;
	// k->makeSound();
	// l->makeSound();
	// alem->makeSound();
	// delete (alem);
	// delete (k);
	// delete (l);

	// std::cout << "\n";
	return (EXIT_SUCCESS);
}
