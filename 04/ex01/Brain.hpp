/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   Brain.hpp                            :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/09/16 14:27:25      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/09/16 14:35:27     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>

class Brain
{
	private:
		std::string *ideias;

	  public:
	///////////////////////////////////////////////// Canonical Orthodox Form //
	Brain();

	Brain(const Brain &other);
	Brain &operator=(const Brain &other);

	virtual ~Brain();
};

#endif
