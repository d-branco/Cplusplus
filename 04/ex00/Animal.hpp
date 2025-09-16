/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   Animal.hpp                           :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/09/16 11:16:56      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/09/16 11:31:26     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal
{
	protected:
		std::string type_;

	public:
		///////////////////////////////////////////// Canonical Orthodox Form //
		Animal(std::string type);

		Animal(const Animal &other);
		Animal &operator=(const Animal &other);

		virtual ~Animal();
};

#endif
