/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   Animal.hpp                           :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/09/18 13:47:18      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/09/18 13:54:40     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
  protected:
    std::string type_;

  public:
    ///////////////////////////////////////////////// Canonical Orthodox Form //
    Animal();
    Animal(std::string type);

    Animal(const Animal &other);
    Animal &operator=(const Animal &other);

    virtual ~Animal();

    ///////////////////////////////////////////////////////////////// Getters //
    std::string  getType() const;

    /////////////////////////////////////////////////////////////// Functions //
    virtual void makeSound() const = 0;
};

#endif
