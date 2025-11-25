/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   Serializer.hpp                       :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/11/25 10:55:58      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/11/25 12:35:54     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#ifndef DEBUG
# define DEBUG false
#endif

#include <iostream>
#include <stdint.h>

#include "Data.hpp"

class Serializer
{
  private:
  public:
	///////////////////////////////////////////////// Canonical Orthodox Form //
	Serializer();
	Serializer(const Serializer &other);
	Serializer &operator=(const Serializer &other);
	~Serializer();

	///////////////////////////////////////////////////////////////// Getters //
	///////////////////////////////////////////////////////////////// Setters //
	/////////////////////////////////////////////////////////////// Functions //
	static uintptr_t serialize(Data *ptr);
	static Data		*deserialize(uintptr_t raw);
};

#endif
