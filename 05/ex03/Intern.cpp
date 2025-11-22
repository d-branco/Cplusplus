/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   Intern.cpp                           :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/11/22 14:05:46      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/11/22 14:48:55     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include "Intern.hpp"

///////////////////////////////////////////////////// Canonical Orthodox Form //
Intern::Intern()
{
	if (DEBUG)
	{
		std::cout << "==DEBUG== Intern: Default Constructor\n";
	}
}

Intern::Intern(const Intern &other)
{
	if (DEBUG)
	{
		std::cout << "==DEBUG== Intern: Copy Constructor\n";
	}
	*this = other;
}

Intern &Intern::operator=(const Intern &other)
{
	if (DEBUG)
	{
		std::cout << "==DEBUG== Intern: Copy Operator Constructor\n";
	}
	if (this == &other)
	{
		return (*this);
	}

	return (*this);
}

Intern::~Intern()
{
	if (DEBUG)
	{
		std::cout << "==DEBUG== Intern: Destructor\n";
	}
}

///////////////////////////////////////////////////////////////////// Getters //
///////////////////////////////////////////////////////////////////// Setters //
/////////////////////////////////////////////////////////////////// Functions //
AForm *Intern::makeForm(const std::string &form_name,
						const std::string &form_target)
{
	if (DEBUG)
	{
		std::cout << "==DEBUG== Intern: makeForm\n"
				  << "==DEBUG==   ├─name: " << form_name << "\n"
				  << "==DEBUG==   └─target: " << form_target << "\n";
	}
	std::string form_list[3]
		= {"presidential pardon", "robotomy request", "shrubbery creation"};

	AForm *(Intern::*form_factory[3])(std::string const &)
		= {&Intern::create_presidential_form,
		   &Intern::create_robotomy_form,
		   &Intern::create_shrubbery_form};

	for (int i = 0; i < 3; i++)
	{
		if (form_list[i] == form_name)
		{
			// std::cout << "Intern creates " << form_name << " for " <<
			// form_target << ".\n";
			std::cout << "Intern creates " << form_name << "\n";
			return ((this->*form_factory[i])(form_target));
		}
	}

	throw Intern::LostForm();
	return (NULL);
}

AForm *Intern::create_presidential_form(std::string const &form_target)
{
	return (new PresidentialPardonForm(form_target));
}

AForm *Intern::create_shrubbery_form(std::string const &form_target)
{
	return (new ShrubberyCreationForm(form_target));
}

AForm *Intern::create_robotomy_form(std::string const &form_target)
{
	return (new RobotomyRequestForm(form_target));
}

////////////////////////////////////////////////////////////////// Exceptions //
const char *Intern::LostForm::what() const throw()
{
	return ("Error:\n  Form  could not be foun!");
}
