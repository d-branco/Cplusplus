/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   Bureaucrat.cpp                       :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/10/28 18:29:32      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/10/30 15:25:28     #########  #########  ###      ###      */
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
	std::cout << "Default Destructor: " << name_ << "(" << grade_ << ")\n";
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
	std::cout << "Bureaucrat " << name_ << "'s grade increased by " << increment
			  << " (" << grade_ << ")\n";
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
	std::cout << "Bureaucrat " << name_ << "'s grade decreased by " << decrement
			  << " (" << grade_ << ")\n";
}

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
