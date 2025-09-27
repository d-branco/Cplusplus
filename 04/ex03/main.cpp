/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   main.cpp                             :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/09/18 17:24:45      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/09/18 17:35:23     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include <cstdlib>

#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

#ifndef DEBUG
# define DEBUG false
#endif

// Notes:

// Interfaces are... something. That "something" does not exits in C++98.
// Why is this not a specification on a documentation is the big question.

int main()
{
    // AMateria cannot_create; // for testing purposes only

    ////////////////////////////////////////////////// Subject example starts //
    // IMateriaSource* src = new MateriaSource();
    // src->learnMateria(new Ice());
    // src->learnMateria(new Cure());

    // ICharacter* me = new Character("me");

    // AMateria* tmp;
    // tmp = src->createMateria("ice");
    // me->equip(tmp);
    // tmp = src->createMateria("cure");
    // me->equip(tmp);

    // ICharacter* bob = new Character("bob");

    // me->use(0, *bob);
    // me->use(1, *bob);

    // delete bob;
    // delete me;
    // delete src;
    //////////////////////////////////////////////////// Subject example ends //

    if (DEBUG)
    {
        std::cout << "Goodbye\n";
    }

    return (EXIT_SUCCESS);
}
