/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   AMateria.hpp                         :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/09/27 15:44:45      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/09/27 15:47:35     #########  #########  ###      ###      */
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
  private:
    AMateria(const AMateria &other);
    AMateria &operator=(const AMateria &other);

  protected:
    AMateria();
    const std::string type_;
    //[...]

  public:
    AMateria(std::string const &type);

    virtual ~AMateria();

    //[...]
    std::string const &getType() const;

    virtual AMateria  *clone() const = 0;
    virtual void       use(ICharacter &target);
};

#endif
