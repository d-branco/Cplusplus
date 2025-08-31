/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   main.hpp                             :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/08/31 11:44:00      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/08/31 11:47:48     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

#ifndef DEBUG
# define DEBUG 0
#endif

#include "Zombie.hpp"

Zombie *newZombie(std::string name);
void	randomChump(std::string name);

#endif
