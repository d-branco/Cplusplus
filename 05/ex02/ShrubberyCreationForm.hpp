/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   ShrubberyCreationForm.hpp            :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/11/22 11:03:25      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/11/22 13:27:26     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <fstream>
#include <iostream>

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
  private:
	std::string target_;

  public:
	///////////////////////////////////////////////// Canonical Orthodox Form //
	ShrubberyCreationForm(const std::string &target);
	ShrubberyCreationForm(const ShrubberyCreationForm &other);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
	virtual ~ShrubberyCreationForm();

	///////////////////////////////////////////////////////////////// Getters //
	///////////////////////////////////////////////////////////////// Setters //
	/////////////////////////////////////////////////////////////// Functions //
	virtual void execute(Bureaucrat const &executor) const;
};

#endif
