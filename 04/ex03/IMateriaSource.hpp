/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   IMateriaSource.hpp                   :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/09/27 11:40:20      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/09/27 11:40:46     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include "AMateria.hpp"
#include <string>

class IMateriaSource
{
  public:
    virtual ~IMateriaSource()
    {
    }

    virtual void      learnMateria(AMateria *)               = 0;
    virtual AMateria *createMateria(std::string const &type) = 0;
};

#endif
