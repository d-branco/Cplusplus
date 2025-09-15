/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   ClapTrap.hpp                         :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/09/15 16:31:42      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/09/15 17:18:49     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
  protected:
	std::string	 name_;
	unsigned int hit_;
	unsigned int energy_;
	unsigned int attack_;

  public:
	ClapTrap(const std::string &name);

	ClapTrap(const ClapTrap &other);
	ClapTrap &operator=(const ClapTrap &other);

	virtual ~ClapTrap();

	std::string	 get_name();
	unsigned int get_hit();

	void		 increment_hit(int change);

	void		 attack(const std::string &target);
	void		 takeDamage(unsigned int amount);
	void		 beRepaired(unsigned int amount);
};

#endif
