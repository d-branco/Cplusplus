/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   PresidentialPardonForm.cpp           :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/11/22 11:05:24      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/11/22 12:38:15     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

///////////////////////////////////////////////////// Canonical Orthodox Form //
PresidentialPardonForm::PresidentialPardonForm(const std::string &target) :
	AForm("Presidential Pardon", false, 25, 5),
	target_(target)
{
	if (DEBUG)
	{
		std::cout << "==DEBUG== Presidential Pardon Form: Constructor: target: "
				  << target_ << "\n";
	}
}

PresidentialPardonForm::PresidentialPardonForm(
	const PresidentialPardonForm &other) :
	AForm(other),
	target_(other.target_)
{
	if (DEBUG)
	{
		std::cout << "==DEBUG== Presidential Pardon Form: Copy Constructor\n";
	}
}

PresidentialPardonForm &
PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (DEBUG)
	{
		std::cout << "==DEBUG== Presidential Pardon Form: Copy Assignment\n";
	}
	if (this == &other)
	{
		return (*this);
	}

	AForm::operator=(other);
	this->target_ = other.target_;

	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	if (DEBUG)
	{
		std::cout << "==DEBUG== Presidential Pardon Form: Destructor\n";
	}
}

///////////////////////////////////////////////////////////////////// Getters //
///////////////////////////////////////////////////////////////////// Setters //
/////////////////////////////////////////////////////////////////// Functions //
void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (!this->get_signed_state())
	{
		throw AForm::UnSignedException();
	}
	if (executor.getGrade() > this->get_min_grade_to_execute())
	{
		throw AForm::GradeTooLowException();
	}

	std::cout << "Zaphod Beeblebrox has graciouslly pardoned " << target_
			  << "!\n";
}
