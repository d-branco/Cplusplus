/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   Character.hpp                        :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/09/27 11:38:23      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/09/27 11:41:04     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#ifndef DEBUG
# define DEBUG false
#endif

#include "ICharacter.hpp"

#include <string>

class Character : public ICharacter
{
	private:
		std::string name_;
		
	public:
    Character();

    Character(const Character &other);
    Character &operator=(const Character &other);

    virtual ~Character();

	// from ICharacter
	virtual std::string const &getName() const                  = 0;
	virtual void               equip(AMateria *m)               = 0;
	virtual void               unequip(int idx)                 = 0;
	virtual void               use(int idx, ICharacter &target) = 0;

};

#endif
