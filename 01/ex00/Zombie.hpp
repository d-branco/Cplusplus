/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   Zombie.hpp                           :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/08/31 13:57:40      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/09/01 13:30:42     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>

class Zombie
{
  private:
	std::string name;

  public:
	Zombie(std::string name);
	~Zombie();
	void announce(void);
};

#endif
