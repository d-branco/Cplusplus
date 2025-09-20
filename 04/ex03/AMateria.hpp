/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   AMateria.hpp                         :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/09/18 17:37:09      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/09/18 17:43:53     #########  #########  ###      ###      */
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
