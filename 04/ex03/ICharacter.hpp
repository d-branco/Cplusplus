/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   ICharacter.hpp                       :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/09/20 16:43:07      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/09/24 17:31:23     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include "AMateria.hpp"
#include <string>

class ICharacter
{
  private:
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
