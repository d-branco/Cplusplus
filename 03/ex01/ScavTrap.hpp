/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   ScavTrap.hpp                         :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/09/15 16:33:56      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/09/15 17:45:47     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
  private:
	int mode_;

  public:
	ScavTrap(std::string name_);

	ScavTrap(const ScavTrap &other);
	ScavTrap &operator=(const ScavTrap &other);

	virtual ~ScavTrap();

	void guardGate();
};

#endif
