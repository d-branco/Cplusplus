/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   MateriaSource.hpp                    :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/09/27 11:40:20      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/09/27 11:41:46     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

class MaterialSource
{
  private:
    MaterialSource();

    MaterialSource(const MaterialSource &other);
    MaterialSource &operator=(const MaterialSource &other);

  public:
    virtual ~MaterialSource();
};

#endif
