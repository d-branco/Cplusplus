/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   PresidentialPardonForm.hpp           :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/11/22 11:05:24      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/11/22 11:05:24     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm
{
  private:
  public:
	///////////////////////////////////////////////// Canonical Orthodox Form //
	PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm &other);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
	~PresidentialPardonForm();

	///////////////////////////////////////////////////////////////// Getters //
	///////////////////////////////////////////////////////////////// Setters //
	/////////////////////////////////////////////////////////////// Functions //
};

#endif
