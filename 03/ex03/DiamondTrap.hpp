/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   DiamondTrap.hpp                      :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/09/16 07:10:08      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/09/16 07:49:21     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
  private:
	std::string name_;

  public:
	DiamondTrap(std::string name_);

	DiamondTrap(const DiamondTrap &other);
	DiamondTrap &operator=(const DiamondTrap &other);

	virtual ~DiamondTrap();

	void attack(const std::string &target);
	void whoAmI();
};

#endif
