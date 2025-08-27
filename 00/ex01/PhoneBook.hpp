/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   PhoneBook.hpp                        :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/08/28 21:37:45      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/08/28 21:40:30     #########  #########  ###      ###      */
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
	int		current_log_;
	Contact line[8];

  public:
	PhoneBook(); //////////////////////////////////////////////// Constructor //
	~PhoneBook(); //////////////////////////////////////////////// Destructor //
	// PhoneBook(const PhoneBook &other); ////////////////////////////// Copy //
	// PhoneBook &operator=(const PhoneBook &other); ////////// Operator copy //
	void add_contact();	   //////////////////////////////// Add a new contact //
	void search_contact(); /////////////////////////////////// Search contact //

	// const Contact &get_line(int index) const;///////////////////// Getters //
	///////////////////////////////////////////////////////////////// Setters //
};

#endif
