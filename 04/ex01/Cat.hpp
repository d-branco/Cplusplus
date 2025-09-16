/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   Cat.hpp                              :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/09/16 16:22:55      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/09/16 18:12:40     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
  private:
	Brain *cat_brain_;

  public:
	Cat();
	Cat(std::string type);

	Cat(const Cat &other);
	Cat &operator=(const Cat &other);

	virtual ~Cat();

	void makeSound() const;
};

#endif
