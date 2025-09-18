/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   WrongAnimal.hpp                      :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/09/16 13:57:59      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/09/16 14:05:43     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal
{
  protected:
    std::string type_;

  public:
    ///////////////////////////////////////////////// Canonical Orthodox Form //
    WrongAnimal();
    WrongAnimal(std::string type);

    WrongAnimal(const WrongAnimal &other);
    WrongAnimal &operator=(const WrongAnimal &other);

    virtual ~WrongAnimal();

    ///////////////////////////////////////////////////////////////// Getters //
    std::string getType() const;

    /////////////////////////////////////////////////////////////// Functions //
    void        makeSound() const;
};

#endif
