/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   Cat.hpp                              :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/09/16 12:31:03      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/09/16 12:37:40     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
  public:
	Cat(std::string type);

	Cat(const Cat &other);
	Cat &operator=(const Cat &other);

	virtual ~Cat();
};

#endif
