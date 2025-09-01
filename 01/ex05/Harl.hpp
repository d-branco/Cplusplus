/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   Harl.hpp                             :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/09/01 12:06:03      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/09/01 12:06:27     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

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
