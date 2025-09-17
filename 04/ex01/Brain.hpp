/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   Brain.hpp                            :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/09/16 15:56:45      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/09/16 17:40:07     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain
{
  private:
    std::string *ideas_;

  public:
    ///////////////////////////////////////////////// Canonical Orthodox Form //
    Brain();

    Brain(const Brain &other);
    Brain &operator=(const Brain &other);

    virtual ~Brain();

    ///////////////////////////////////////////////////////////////// Getters //
    Brain             &getBrain();
    const Brain       &getBrain() const;

    /////////////////////////////////////////////////////////////// Functions //
    std::string       &operator[](size_t index);
    const std::string &operator[](size_t index) const;
};

#endif
