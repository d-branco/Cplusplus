/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   Contact.hpp                          :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/08/28 21:37:45      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/08/30 17:54:28     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <string>

class Contact
{
  private:
	std::string name_;
	std::string surname_;
	std::string nick_;
	std::string phone_number_;
	std::string secret_;

  public:
	Contact(); ////////////////////////////////////////////////// Constructor //
	Contact(const std::string &name,
			const std::string &surname,
			const std::string &nick,
			const std::string &phone_number,
			const std::string &secret);
	~Contact(); ////////////////////////////////////////////////// Destructor //
	Contact(const Contact &other); ///////////////////////////////////// Copy //
	Contact	   &operator=(const Contact &other); /////////////////////// Copy //
	///////////////////////////////////////////////////////////////// Getters //
	std::string get_name() const;
	std::string get_surname() const;
	std::string get_nick() const;
	std::string get_phone_number() const;
	std::string get_secret() const;
	///////////////////////////////////////////////////////////////// Setters //
	void		set_name(const std::string &new_name);
	void		set_surname(const std::string &new_surname);
	void		set_nick(const std::string &new_nick);
	void		set_phone_number(const std::string &new_phone_number);
	void		set_secret(const std::string &new_secret);
};

#endif
