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

#ifndef DEBUG
# define DEBUG false
#endif

#include <iostream>
#include <string>

#include "ICharacter.hpp"

// class "Abstract Materia"
class AMateria
{
  protected:
    AMateria();

    const std::string type_;
    //[...]

  public:
    AMateria(std::string const &type);

    AMateria(const AMateria &other);
    AMateria &operator=(const AMateria &other);

    virtual ~AMateria();

    //[...]
    std::string const &getType() const; // Returns the materia type

    virtual AMateria  *clone() const = 0;
    virtual void       use(ICharacter &target);
};

#endif
