/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   Brain.hpp                            :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/09/18 07:40:41      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/09/18 08:56:19     #########  #########  ###      ###      */
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

    /////////////////////////////////////////////////////////////// Functions //
    std::string       &operator[](size_t index);
    const std::string &operator[](size_t index) const;
};

#endif
