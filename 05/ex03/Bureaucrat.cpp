/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   Bureaucrat.cpp                       :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/10/28 18:29:32      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/11/22 14:05:46     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

///////////////////////////////////////////////////// Canonical Orthodox Form //
// Bureaucrat::Bureaucrat()
// {
// 	std::cout << "Error: Nameless, gradeless Bureaucrat.\n";
// 	std::cout << "Note: this Constructor exists merely for Orthodox Canonical "
// 				 "Form bureaucracy's sake.\n";
// }

Bureaucrat::Bureaucrat(const std::string &name, int grade) :
	name_(name),
	grade_(grade)
{
	if (DEBUG)
	{
		std::cout << "==DEBUG== Default Constructor: " << name_ << "(" << grade_
				  << ")\n";
	}
	if (grade_ < 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	if (grade_ > 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) :
	name_(other.name_),
	grade_(other.grade_)
{
	if (DEBUG)
	{
		std::cout << "==DEBUG== Copy Constructor: " << this->name_ << "\n";
	}
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	std::cout << "==DEBUG== Copy Operator Constructor: " << this->name_ << "\n";
	if (this == &other)
	{
		return (*this);
	}

	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	if (DEBUG)
	{
		std::cout << "==DEBUG== Default Destructor: " << name_ << "(" << grade_
				  << ")\n";
	}
}

///////////////////////////////////////////////////////////////////// Getters //
const std::string &Bureaucrat::getName() const
{
	return (name_);
}

int Bureaucrat::getGrade() const
{
	return (grade_);
}

///////////////////////////////////////////////////////////////////// Setters //
void Bureaucrat::grade_increment(int increment)
{
	if (increment <= 0)
	{
		return;
	}
	if ((this->grade_ - increment) < 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	this->grade_ -= increment;
	if (DEBUG)
	{
		std::cout << "==DEBUG== Bureaucrat " << name_
				  << "'s grade increased by " << increment << " (" << grade_
				  << ")\n";
	}
}

void Bureaucrat::grade_decrement(int decrement)
{
	if (decrement <= 0)
	{
		return;
	}
	if ((this->grade_ + decrement) > 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
	this->grade_ += decrement;
	if (DEBUG)
	{
		std::cout << "==DEBUG== Bureaucrat " << name_
				  << "'s grade decreased by " << decrement << " (" << grade_
				  << ")\n";
	}
}

/////////////////////////////////////////////////////////////////// Functions //
void Bureaucrat::signForm(AForm &form_to_sign)
{
	if (DEBUG)
	{
		std::cout << "==DEBUG== Bureaucrat " << name_ << " is signing "
				  << form_to_sign.get_name() << ".\n";
	}
	form_to_sign.beSigned(*this);
	std::cout << name_ << " signed " << form_to_sign.get_name() << "\n";
}

void Bureaucrat::executeForm(AForm const &form_to_exe)
{
	if (DEBUG)
	{
		std::cout << "==DEBUG== Bureaucrat " << name_ << " is executing "
				  << form_to_exe.get_name() << ".\n";
	}
	form_to_exe.execute(*this);
	std::cout << "Bureaucrat " << name_ << " executed "
			  << form_to_exe.get_name() << "\n";
}

////////////////////////////////////////////////////////////////// Exceptions //
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Error:\n  Grade cannot be above 1");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Error:\n  Grade cannot be bellow 150");
}

////////////////////////////////////////////////////////// Overload operators //
std::ostream &operator<<(std::ostream &out_s, const Bureaucrat &bureaucrat)
{
	out_s << bureaucrat.getName() << ", bureaucrat grade "
		  << bureaucrat.getGrade();

	return (out_s);
}
