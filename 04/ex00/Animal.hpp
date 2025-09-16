/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   Animal.hpp                           :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/09/16 13:33:00      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/09/16 13:35:14     #########  #########  ###      ###      */
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
	std::string	 getType() const;

	/////////////////////////////////////////////////////////////// Functions //
	virtual void makeSound() const;
};

#endif
