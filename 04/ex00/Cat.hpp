/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   Cat.hpp                              :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/09/16 13:06:31      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/09/16 13:31:48     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
  public:
	Cat();
	Cat(std::string type);

	Cat(const Cat &other);
	Cat &operator=(const Cat &other);

	virtual ~Cat();

	void makeSound() const;
};

#endif
