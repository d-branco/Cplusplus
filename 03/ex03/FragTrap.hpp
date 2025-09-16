/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   FragTrap.hpp                         :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/09/16 06:14:48      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/09/16 06:24:21     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

#include <iostream>
#include <string>

class FragTrap : public ClapTrap
{
  private:
	int mode_;

  public:
	FragTrap(std::string name_);

	FragTrap(const FragTrap &other);
	FragTrap &operator=(const FragTrap &other);

	virtual ~FragTrap();

	void highFivesGuys(void);
};

#endif
