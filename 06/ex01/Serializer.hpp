/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   Serializer.hpp                       :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/11/25 10:55:58      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/11/25 11:04:31     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#ifndef DEBUG
# define DEBUG false
#endif

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
};

#endif
