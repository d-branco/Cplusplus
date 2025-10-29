/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   Bureaucrat.cpp                       :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/10/28 18:29:32      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/10/29 09:53:18     #########  #########  ###      ###      */
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
	std::cout << "Default Constructor: " << name_ << "(" << grade_ << ")\n";
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
	std::cout << "Copy Constructor: " << this->name_ << "\n";
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	std::cout << "Copy Operator Constructor: " << this->name_ << "\n";
	if (this == &other)
	{
		return (*this);
	}

	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Default Destructor: " << name_ << "\n";
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
/////////////////////////////////////////////////////////////////// Functions //
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
std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade "
	   << bureaucrat.getGrade();

	return (os);
}
