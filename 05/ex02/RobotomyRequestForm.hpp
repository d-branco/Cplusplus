/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   RobotomyRequestForm.hpp              :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/11/22 11:03:36      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/11/22 12:15:37     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm
{
  private:
  public:
	///////////////////////////////////////////////// Canonical Orthodox Form //
	RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm &other);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
	~RobotomyRequestForm();

	///////////////////////////////////////////////////////////////// Getters //
	///////////////////////////////////////////////////////////////// Setters //
	/////////////////////////////////////////////////////////////// Functions //
};

#endif
