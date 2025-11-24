/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   Base.hpp                             :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/11/24 18:47:35      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/11/24 19:08:23     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#ifndef DEBUG
# define DEBUG false
#endif

#include <ctime>
#include <iostream>
#include <cstdlib>

class Base
{
  private:
  public:
	///////////////////////////////////////////////// Canonical Orthodox Form //
	Base();
	// Base(const Base &other);
	// Base &operator=(const Base &other);
	virtual ~Base();

	///////////////////////////////////////////////////////////////// Getters //
	///////////////////////////////////////////////////////////////// Setters //
	/////////////////////////////////////////////////////////////// Functions //
	Base *generate(void);
};

#endif
