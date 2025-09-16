/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   Dog.hpp                              :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/09/16 16:40:12      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/09/16 16:41:53     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : virtual public Animal
{
  private:
	Brain dog_brain_;

  public:
	Dog();
	Dog(std::string type_);

	Dog(const Dog &other);
	Dog &operator=(const Dog &other);

	virtual ~Dog();

	void makeSound() const;
};

#endif
