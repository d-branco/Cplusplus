/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   Bureaucrat.hpp                       :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/10/28 18:29:32      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/10/29 08:48:10     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

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
	/////////////////////////////////////////////////////////////// Functions //
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

#endif
