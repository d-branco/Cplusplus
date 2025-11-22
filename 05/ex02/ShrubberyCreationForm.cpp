/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   ShrubberyCreationForm.cpp            :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/11/22 11:03:25      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/11/22 13:27:49     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

///////////////////////////////////////////////////// Canonical Orthodox Form //
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) :
	AForm("Shrubbery Creation ", false, 145, 137),
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

	std::string	  file_name = target_ + "_shrubbery";
	std::ofstream file(file_name.c_str());
	if (file.is_open())
	{
		file << "               ,@@@@@@@,\n";
		file << "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n";
		file << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n";
		file << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n";
		file << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n";
		file << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n";
		file << "   `&%\\ ` /%&'    |.|        \\ '|8'\n";
		file << "       |o|        | |         | |\n";
		file << "       |.|        | |         | |\n";
		file << "     \\/ ._\\//_/__/  ,\\_//__\\\\.  \\_//__/_\n";
		file.close();
	}
}
