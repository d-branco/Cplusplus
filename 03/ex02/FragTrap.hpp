/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   FragTrap.hpp                         :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/09/16 05:57:56      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/09/16 06:33:59     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
  public:
	FragTrap(std::string name_);

	FragTrap(const FragTrap &other);
	FragTrap &operator=(const FragTrap &other);

	virtual ~FragTrap();

	void highFivesGuys(void);
};

#endif
