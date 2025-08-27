/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   Contact.hpp                          :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/08/28 18:36:23      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/08/28 19:10:57     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#ifndef CONTACT_H
#define CONTACT_H

#include "yellow_pages.hpp"
#include <string>

class Contact
{
  private:
	std::string name;
	std::string surname;
	std::string nick;
	int			phone_number;
	std::string secret;

  public:
	// Contact(); //////////////////////////////////////////////// Constructor
	// //
	Contact(const std::string &name,
			const std::string &surname,
			const std::string &nick,
			int				   phone_number,
			const std::string &secret);
	~Contact(); ////////////////////////////////////////////////// Destructor //
	Contact(const Contact &other); ///////////////////////////////////// Copy //
	Contact	   &operator=(const Contact &other); /////////////////////// Copy //
	///////////////////////////////////////////////////////////////// Getters //
	std::string get_name() const;
	std::string get_surname() const;
	std::string get_nick() const;
	int			get_phone_number() const;
	std::string get_secret() const;
	///////////////////////////////////////////////////////////////// Setters //
	void		set_name(const std::string &new_name);
	void		set_surname(const std::string &new_surname);
	void		set_nick(const std::string &new_nick);
	void		set_phone_number(int new_phone_number);
	void		set_secret(const std::string &new_secret);
};

#endif
