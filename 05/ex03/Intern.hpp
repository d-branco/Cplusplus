/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   Intern.hpp                           :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/11/22 14:05:46      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/11/22 14:48:47     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
  private:
  public:
	///////////////////////////////////////////////// Canonical Orthodox Form //
	Intern();
	Intern(const Intern &other);
	Intern &operator=(const Intern &other);
	~Intern();

	///////////////////////////////////////////////////////////////// Getters //
	///////////////////////////////////////////////////////////////// Setters //
	/////////////////////////////////////////////////////////////// Functions //
	AForm *makeForm(const std::string &form_name,
					const std::string &form_target);
	AForm *create_shrubbery_form(std::string const &target);
	AForm *create_robotomy_form(std::string const &target);
	AForm *create_presidential_form(std::string const &target);

	////////////////////////////////////////////////////////////// Exceptions //
	class LostForm : public std::exception
	{
	  public:
		virtual const char *what() const throw();
	};
};

#endif
