/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   RobotomyRequestForm.cpp              :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/11/22 11:03:36      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/11/22 13:03:39     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

///////////////////////////////////////////////////// Canonical Orthodox Form //
RobotomyRequestForm::RobotomyRequestForm(const std::string &target) :
	AForm("Robotomy Request", false, 72, 45),
	target_(target)
{
	if (DEBUG)
	{
		std::cout << "==DEBUG== Robotomy Request Form: Constructor: target: "
				  << target_ << "\n";
	}
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) :
	AForm(other),
	target_(other.target_)
{
	if (DEBUG)
	{
		std::cout << "==DEBUG== Robotomy Request Form: Copy Constructor\n";
	}
}

RobotomyRequestForm &
RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (DEBUG)
	{
		std::cout << "==DEBUG== Robotomy Request Form: Copy Assignment\n";
	}
	if (this == &other)
	{
		return (*this);
	}

	AForm::operator=(other);
	this->target_ = other.target_;

	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	if (DEBUG)
	{
		std::cout << "==DEBUG== Robotomy Request Form: Destructor\n";
	}
}

///////////////////////////////////////////////////////////////////// Getters //
///////////////////////////////////////////////////////////////////// Setters //
/////////////////////////////////////////////////////////////////// Functions //
void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (!this->get_signed_state())
	{
		throw AForm::UnSignedException();
	}
	if (executor.getGrade() > this->get_min_grade_to_execute())
	{
		throw AForm::GradeTooLowException();
	}

	std::cout << "Drilling noises begin to sound near " << target_;
	if (std::rand() % 2 == 0)
	{
		std::cout << ". It looks the same but has a new spring in its step.\n";
	}
	else
	{
		std::cout << ". It looks the same.\n";
	}
}
