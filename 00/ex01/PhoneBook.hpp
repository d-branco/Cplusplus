/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   PhoneBook.hpp                        :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/08/30 18:02:52      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/08/30 18:08:34     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"
#include "yellow_pages.hpp"

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>

class PhoneBook
{
  private:
	int			current_log_;
	Contact		line_[MAX_LOG];
	std::string get_string(const std::string &str) const;
	void		print_padded(const std::string &str) const;

  public:
	PhoneBook(); //////////////////////////////////////////////// Constructor //
	~PhoneBook(); //////////////////////////////////////////////// Destructor //
	PhoneBook(const PhoneBook &other); ///////////////////////////////// Copy //
	PhoneBook &operator=(const PhoneBook &other); ///////////// Operator copy //
	void add_contact();	   //////////////////////////////// Add a new contact //
	void search_contact(); /////////////////////////////////// Search contact //

	///////////////////////////////////////////////////////////////// Getters //
	///////////////////////////////////////////////////////////////// Setters //
};

#endif
