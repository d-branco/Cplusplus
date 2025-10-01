/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   Dog.hpp                              :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/09/18 13:47:18      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/10/01 14:08:37     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : virtual public Animal
{
  private:
    Brain *dog_brain_;

  public:
    Dog();
    Dog(std::string type_);

    Dog(const Dog &other);
    Dog &operator=(const Dog &other);

    virtual ~Dog();

    void              makeSound() const;

    std::string       get_brain_idea(size_t index);
    const std::string get_brain_idea(size_t index) const;

    void              set_brain_idea(size_t index, std::string str);
};

#endif
