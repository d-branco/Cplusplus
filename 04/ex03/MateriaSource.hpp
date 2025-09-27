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

#include "IMateriaSource.hpp"

#define INVENTORY_SIZE 4

class MateriaSource : public IMateriaSource
{
  private:
    AMateria  *inventory_[INVENTORY_SIZE];

  public:
	MateriaSource();

	MateriaSource(const MateriaSource &other);
	MateriaSource &operator=(const MateriaSource &other);

  ~MateriaSource();

	void	  learnMateria(AMateria *);
	AMateria *createMateria(std::string const &type);
};

#endif
