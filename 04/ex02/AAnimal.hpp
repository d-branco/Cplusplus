/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   AAnimal.hpp                          :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/09/18 13:47:18      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/09/26 09:08:39     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

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
