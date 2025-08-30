/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   PhoneBook.hpp                        :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/08/30 15:40:35      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/08/30 15:42:31     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"
#include "yellow_pages.hpp"

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
	// PhoneBook(const PhoneBook &other); ////////////////////////////// Copy //
	// PhoneBook &operator=(const PhoneBook &other); ////////// Operator copy //
	void add_contact();	   //////////////////////////////// Add a new contact //
	void search_contact(); /////////////////////////////////// Search contact //

	// const Contact &get_line(int index) const;///////////////////// Getters //
	///////////////////////////////////////////////////////////////// Setters //
};

#endif
