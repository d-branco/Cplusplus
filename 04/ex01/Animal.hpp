/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   Animal.hpp                           :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/09/16 14:08:35      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/09/16 18:41:15     #########  #########  ###      ###      */
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
