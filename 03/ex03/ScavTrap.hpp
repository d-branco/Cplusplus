/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   ScavTrap.hpp                         :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/09/16 09:19:01      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/09/20 12:35:16     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
  private:
	int mode_;

  protected:
	static const unsigned int initial_energy = 50;

  public:
	ScavTrap(std::string name_ST);

	ScavTrap(const ScavTrap &other);
	ScavTrap &operator=(const ScavTrap &other);

	virtual ~ScavTrap();

	void guardGate();
};

#endif

int main()

{
}
