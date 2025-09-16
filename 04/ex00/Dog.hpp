/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   Dog.hpp                              :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/09/16 12:50:33      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/09/16 13:31:38     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : virtual public Animal
{
  public:
	Dog();
	Dog(std::string type_);

	Dog(const Dog &other);
	Dog &operator=(const Dog &other);

	virtual ~Dog();

	void makeSound() const;
};

#endif
