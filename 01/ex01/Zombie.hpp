/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   Zombie.hpp                           :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/08/31 15:43:31      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/08/31 15:44:10     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>

class Zombie
{
  private:
	std::string name;
	Zombie	   *horde;

  public:
	Zombie(std::string name);
	Zombie();
	void		announce(void);
	void		set_name(std::string name);
	std::string get_name();
};

#endif
