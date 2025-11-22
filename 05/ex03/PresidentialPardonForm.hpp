/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   PresidentialPardonForm.hpp           :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/11/22 11:05:24      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/11/22 14:05:46     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
  private:
	std::string target_;

  public:
	///////////////////////////////////////////////// Canonical Orthodox Form //
	PresidentialPardonForm(const std::string &target);
	PresidentialPardonForm(const PresidentialPardonForm &other);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
	virtual ~PresidentialPardonForm();

	///////////////////////////////////////////////////////////////// Getters //

	///////////////////////////////////////////////////////////////// Setters //

	/////////////////////////////////////////////////////////////// Functions //
	virtual void execute(Bureaucrat const &executor) const;
};

#endif
