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

class MaterialSrouce
{
  private:
    MaterialSrouce();

    MaterialSrouce(const MaterialSrouce &other);
    MaterialSrouce &operator=(const MaterialSrouce &other);

  public:
    virtual ~MaterialSrouce();
};

#endif
