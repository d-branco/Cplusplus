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

#define INVENTORY_SIZE 4

#include "AMateria.hpp"
#include "ICharacter.hpp"

#include <string>

class Character : public ICharacter
{
  private:
	std::string name_;
	AMateria   *inventory_[INVENTORY_SIZE];

	Character();
	void leave_on_the_floor(AMateria *m);

  public:
	Character(const Character &other);
	Character &operator=(const Character &other);

	virtual ~Character();

	// from ICharacter
	std::string const &getName() const;
	void			   equip(AMateria *m);
	void			   unequip(int idx);
	void			   use(int idx, ICharacter &target);
};

#endif
