/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   FragTrap.hpp                         :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/09/16 06:14:48      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/09/16 07:15:31     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
  public:
	FragTrap(std::string name_);

	FragTrap(const FragTrap &other);
	FragTrap &operator=(const FragTrap &other);

	virtual ~FragTrap();

	void highFivesGuys(void);
};

#endif
