/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   Contact.hpp                          :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/08/25 11:53:28      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/08/26 21:18:51     #########  #########  ###      ###      */
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
	///////////////////////////////////////////////////////////// Constructor //
	Contact(std::string name,
			std::string surname,
			std::string nick,
			int			phone_number,
			std::string secret);
	////////////////////////////////////////////////////////////// Destructor //
	~Contact();
	//////////////////////////////////////////////////////////////////// Copy //
	Contact(const Contact &other);
	Contact &operator=(const Contact &other);
	///////////////////////////////////////////////////////////////// Getters //
	std::string get_name() const;
	std::string get_surname() const;
	std::string get_nick() const;
	int			get_phone_number() const;
	std::string get_secret() const;
	///////////////////////////////////////////////////////////////// Setters //
	void set_name(const std::string &name);
	void set_surname(const std::string &surname);
	void set_nick(const std::string &nick);
	void set_phone_number(int phone_number);
	void set_secret(const std::string &secret);
};

#endif
