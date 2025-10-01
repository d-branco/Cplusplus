/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   Cat.hpp                              :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/09/18 13:47:18      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/10/01 14:08:41     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
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
