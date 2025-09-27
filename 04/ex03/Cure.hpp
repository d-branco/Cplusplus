/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   Cure.hpp                             :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/09/20 16:44:21      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/09/24 20:14:36     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#ifndef DEBUG
# define DEBUG false
#endif

#include "AMateria.hpp"

class Cure : public AMateria
{
  private:
	// Cure(std::string const &type);

  public:
	Cure();

	Cure(const Cure &other);
	Cure &operator=(const Cure &other);

	virtual ~Cure();

	virtual AMateria *clone() const;
	virtual void	  use(ICharacter &target);
};

#endif
