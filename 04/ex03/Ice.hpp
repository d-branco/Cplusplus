/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   Ice.hpp                              :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/09/20 16:44:01      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/09/24 17:30:19     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
	private:
		Ice();

	public:
    Ice(std::string const &type);

    Ice(const Ice &other);
    Ice &operator=(const Ice &other);

    virtual ~Ice();

    virtual Ice 	 *clone() const;
    virtual void   use(ICharacter &target);
};

#endif
