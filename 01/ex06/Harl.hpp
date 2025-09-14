/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   Harl.hpp                             :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/09/01 13:03:20      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/09/01 13:11:55     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#ifndef HEAL_H
#define HEAL_H

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>

class Harl
{
  private:
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);

  public:
	void complain(std::string level);
};

#endif
