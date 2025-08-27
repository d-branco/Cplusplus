/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   Contact.hpp                          :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/08/28 16:12:48      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/08/28 16:48:10     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#ifndef CONTACT_H
#define CONTACT_H

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
	Contact(); ////////////////////////////////////////////////// Constructor //
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
	void		set_name(const std::string &name);
	void		set_surname(const std::string &surname);
	void		set_nick(const std::string &nick);
	void		set_phone_number(int phone_number);
	void		set_secret(const std::string &secret);
};

#endif
