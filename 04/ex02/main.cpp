/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   main.cpp                             :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/09/18 14:06:33      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/10/01 14:08:46     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

// Remember to make "the most complete tests"!

#include "AAnimal.hpp"
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

    std::cout << "\n";

    j->makeSound();
    j->makeSound();

    std::cout << "\n";

    delete j;
    delete i;

    std::cout << "\n\n";

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

    for (size_t k = 0; k < 6; k++)
    {
        array[k]->makeSound(); // Polymorphic calls
        delete array[k];
    }

    // Test. Uncommenting any of this ought to give a compiler error:
    // Animal test;
    // Animal test("test_type");
    // Animal *ptr = new Animal();
    // Animal *ptr = new Animal("test_type");

    return (EXIT_SUCCESS);
}
