/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   AMateria.hpp                         :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/09/20 12:17:47      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/09/20 12:17:50     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

class AMateria
{
  protected:
    //[...]

  public:
    AMateria(std::string const &type);
    //[...]

    std::string const &getType() const; // Returns the materia type
    virtual AMateria  *clone() const = 0;
    virtual void       use(ICharacter &target);
};

#endif
