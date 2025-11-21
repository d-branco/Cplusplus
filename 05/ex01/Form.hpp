/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   Form.hpp                             :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/11/21 09:12:38      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/11/21 11:05:06     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <exception>
#include <iostream>
#include <string>

#ifndef DEBUG
# define DEBUG false
#endif

class Form
{
  private:
	const std::string name_;
	bool			  is_signed_;
	const int		  sign_min_grade_;
	const int		  exec_min_grade_;

  public:
	///////////////////////////////////////////////// Canonical Orthodox Form //
	// Form();
	Form(const std::string &name,
		 bool				is_signed,
		 int				sign_min_grade,
		 int				exec_min_grade);
	Form(const Form &other);
	Form &operator=(const Form &other);
	~Form();

	///////////////////////////////////////////////////////////////// Getters //
	const std::string &get_name() const;
	bool			   get_signed_state() const;
	int				   get_min_grade_to_sign() const;
	int				   get_min_grade_to_execute() const;

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

////////////////////////////////////////////////////////// Overload operators //
std::ostream &operator<<(std::ostream &out_s, const Form &Form);

#endif
