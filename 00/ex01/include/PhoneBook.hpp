/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   PhoneBook.hpp                        :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/08/27 08:18:53      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/08/27 08:23:30     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "yellow_pages.hpp"
#include <vector>

class Contact;

class PhoneBook
{
  private:
	const int			 max_log;
	int					 current_log;
	std::vector<Contact> line;

  public:
	///////////////////////////////////////////////////////////// Constructor //
	PhoneBook(int max_log);
	////////////////////////////////////////////////////////////// Destructor //
	~PhoneBook();
	//////////////////////////////////////////////////////////////////// Copy //
	PhoneBook(const PhoneBook &other);
	PhoneBook &operator=(const PhoneBook &other);
	///////////////////////////////////////////////////////////////// Getters //
	const Contact &get_line(int index) const;
	///////////////////////////////////////////////////////////////// Setters //
	/////////////////////////////////////////////////////// Add a new contact //
	void add_contact(const Contact &new_contact);
};

#endif
