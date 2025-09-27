/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   ICharacter.hpp                       :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/09/27 15:44:27      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/09/27 15:52:52     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include <string>

class AMateria;

class ICharacter
{
  protected:
    ICharacter();

    ICharacter(const ICharacter &other);
    ICharacter &operator=(const ICharacter &other);

  public:
    virtual ~ICharacter(){};
    virtual std::string const &getName() const                  = 0;
    virtual void               equip(AMateria *m)               = 0;
    virtual void               unequip(int idx)                 = 0;
    virtual void               use(int idx, ICharacter &target) = 0;
};

#endif
