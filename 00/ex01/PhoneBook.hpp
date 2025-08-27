/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   PhoneBook.hpp                        :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/08/28 16:44:37      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/08/28 16:48:16     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"
#include <iomanip>
#include <iostream>
#include <string>

class PhoneBook
{
  private:
	int		current_log;
	Contact line[8];

  public:
	PhoneBook(); //////////////////////////////////////////////// Constructor //
	~PhoneBook(); //////////////////////////////////////////////// Destructor //
	PhoneBook(const PhoneBook &other); ///////////////////////////////// Copy //
	PhoneBook &operator=(const PhoneBook &other); ///////////// Operator copy //
	void	   add_contact(const Contact &person); //////// Add a new contact //
	void	   search_contact(const Contact &person); //////// Search contact //

	// const Contact &get_line(int index) const;///////////////////// Getters //
	///////////////////////////////////////////////////////////////// Setters //
};

#endif
