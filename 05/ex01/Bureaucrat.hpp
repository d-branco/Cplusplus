/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   Bureaucrat.hpp                       :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/10/28 18:29:32      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/11/21 16:53:11     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#pragma once

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <exception>
# include <iostream>
# include <string>

# include "Form.hpp"

# ifndef DEBUG
#  define DEBUG false
# endif

class Form;

class Bureaucrat
{
  private:
	const std::string name_;
	int				  grade_;

	///////////////////////////////////////////////// Canonical Orthodox Form //
	// Bureaucrat();

  public:
	///////////////////////////////////////////////// Canonical Orthodox Form //
	Bureaucrat(const std::string &name, int grade);
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &other);
	~Bureaucrat();

	///////////////////////////////////////////////////////////////// Getters //
	const std::string &getName() const;
	int				   getGrade() const;

	///////////////////////////////////////////////////////////////// Setters //
	void			   grade_increment(int increment);
	void			   grade_decrement(int decrement);

	/////////////////////////////////////////////////////////////// Functions //
	void			   signForm(Form &form_to_sign);

	////////////////////////////////////////////////////////////// Exceptions //
	class GradeTooHighException : public std::exception
	{
	  public:
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	  public:
		virtual const char *what() const throw();
	};
};

////////////////////////////////////////////////////////// Overload operators //
std::ostream &operator<<(std::ostream &out_s, const Bureaucrat &bureaucrat);

#endif
