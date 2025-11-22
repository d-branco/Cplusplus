/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   ShrubberyCreationForm.cpp            :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/11/22 11:03:25      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/11/22 13:03:39     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

///////////////////////////////////////////////////// Canonical Orthodox Form //
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) :
	AForm("Shrubbery Creation ", false, 72, 45),
	target_(target)
{
	if (DEBUG)
	{
		std::cout << "==DEBUG== Shrubbery Creation Form: Constructor: target: "
				  << target_ << "\n";
	}
}

ShrubberyCreationForm::ShrubberyCreationForm(
	const ShrubberyCreationForm &other) :
	AForm(other),
	target_(other.target_)
{
	if (DEBUG)
	{
		std::cout << "==DEBUG== Shrubbery Creation Form: Copy Constructor\n";
	}
}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (DEBUG)
	{
		std::cout << "==DEBUG== Shrubbery Creation Form: Copy Assignment\n";
	}
	if (this == &other)
	{
		return (*this);
	}

	AForm::operator=(other);
	this->target_ = other.target_;

	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	if (DEBUG)
	{
		std::cout << "==DEBUG== Shrubbery Creation Form: Destructor\n";
	}
}

///////////////////////////////////////////////////////////////////// Getters //
///////////////////////////////////////////////////////////////////// Setters //
/////////////////////////////////////////////////////////////////// Functions //
void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (!this->get_signed_state())
	{
		throw AForm::UnSignedException();
	}
	if (executor.getGrade() > this->get_min_grade_to_execute())
	{
		throw AForm::GradeTooLowException();
	}

	std::cout << target_; // TODO
}
