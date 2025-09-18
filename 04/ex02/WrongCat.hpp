/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   WrongCat.hpp                         :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/09/16 13:40:00      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/09/16 14:05:33     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
  public:
    WrongCat();
    WrongCat(std::string type);

    WrongCat(const WrongCat &other);
    WrongCat &operator=(const WrongCat &other);

    virtual ~WrongCat();

    void makeSound() const;
};

#endif
