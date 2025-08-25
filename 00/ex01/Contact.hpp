/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 08:32:33 by abessa-m          #+#    #+#             */
/*   Updated: 2025/08/25 09:55:20 by abessa-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
#define CONTACT_H

#include <string>

class Contact
{
  private:
	std::string name;
	std::string surname;
	std::string nickname;
	int         phone_number;
	std::string secret;

  public:
	Contact(std::string name,
	        std::string surname,
	        std::string nickname,
	        int         phone_number,
	        std::string secret);
	~Contact();

	Contact(const Contact &other);
	Contact &operator=(const Contact &other);
};

#endif
