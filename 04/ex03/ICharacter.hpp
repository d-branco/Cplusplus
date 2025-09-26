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

class ICharacter
{
  private:
    ICharacter();

    ICharacter(const ICharacter &other);
    ICharacter &operator=(const ICharacter &other);

    virtual ~ICharacter();

  public:

};

#endif
