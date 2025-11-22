/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   Form.cpp                             :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/11/21 09:12:38      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/11/22 10:56:21     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include "AForm.hpp"

///////////////////////////////////////////////////// Canonical Orthodox Form //
// Form::Form()
// {
// }

Form::Form(const std::string &name,
		   bool				  is_signed,
		   const int		  sign_min_grade,
		   const int		  exec_min_grade) :
	name_(name),
	is_signed_(is_signed),
	sign_min_grade_(sign_min_grade),
	exec_min_grade_(exec_min_grade)
{
	if (DEBUG)
	{
		std::cout << "==DEBUG== Default Constructor: \n"
				  << "==DEBUG==   ├─name: " << name_
				  << ". Is signed: " << is_signed_ << "\n"
				  << "==DEBUG==   └─Minimum grade to sign: " << sign_min_grade_
				  << ". Minimum grade to execute: " << exec_min_grade_ << "\n";
	}
	if ((sign_min_grade < 1) || (exec_min_grade < 1))
	{
		throw Form::GradeTooHighException();
	}
	if ((sign_min_grade > 150) || (exec_min_grade > 150))
	{
		throw Form::GradeTooLowException();
	}
}

Form::Form(const Form &other) :
	name_(other.name_),
	is_signed_(other.is_signed_),
	sign_min_grade_(other.sign_min_grade_),
	exec_min_grade_(other.exec_min_grade_)
{
	if (DEBUG)
	{
		std::cout << "==DEBUG== Copy Constructor: " << this->name_ << "\n";
	}
}

Form &Form::operator=(const Form &other)
{
	if (DEBUG)
	{
		std::cout << "==DEBUG== Copy Operator Constructor: " << this->name_
				  << "\n";
	}
	if (this == &other)
	{
		return (*this);
	}
	this->is_signed_ = other.is_signed_;

	return (*this);
}

Form::~Form()
{
	if (DEBUG)
	{
		std::cout << "==DEBUG== Default Destructor: " << name_ << "\n";
	}
}

///////////////////////////////////////////////////////////////////// Getters //
const std::string &Form::get_name() const
{
	return (name_);
}

bool Form::get_signed_state() const
{
	return (is_signed_);
}

int Form::get_min_grade_to_sign() const
{
	return (sign_min_grade_);
}

int Form::get_min_grade_to_execute() const
{
	return (exec_min_grade_);
}

///////////////////////////////////////////////////////////////////// Setters //
/////////////////////////////////////////////////////////////////// Functions //
void Form::beSigned(const Bureaucrat &signer)
{
	if (DEBUG)
	{
		std::cout << "==DEBUG== " << signer.getName() << "(grade "
				  << signer.getGrade() << ") is signning form " << this->name_
				  << ".\n";
	}
	if (this->sign_min_grade_ < signer.getGrade())
	{
		std::cout << signer.getName() << " couldn't sign " << this->name_
				  << " because their grade is too low.\n";
		throw Form::GradeTooLowException();
	}
	this->is_signed_ = true;
}

////////////////////////////////////////////////////////////////// Exceptions //
const char *Form::GradeTooHighException::what() const throw()
{
	return ("Error:\n  Grade cannot be above 1");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Error:\n  Grade is too low.");
}

////////////////////////////////////////////////////////// Overload operators //
std::ostream &operator<<(std::ostream &out_s, const Form &Form)
{
	out_s << Form.get_name() << ", form is ";
	if (!Form.get_signed_state())
	{
		out_s << "not ";
	}
	out_s << "signed.\n  ├─Minimum grade to sign: "
		  << Form.get_min_grade_to_sign() << "\n  └─Minimum grade to execute: "
		  << Form.get_min_grade_to_execute();

	return (out_s);
}
