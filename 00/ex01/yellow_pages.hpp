/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   yellow_pages.hpp                     :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/08/28 21:39:41      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/08/30 10:54:56     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#ifndef YELLOW_PAGES_H
#define YELLOW_PAGES_H

#include <csignal>
#include <cstdlib>
#include <iomanip> //set width with std::setw(size)
#include <iostream>

#include "Contact.hpp"
#include "PhoneBook.hpp"

enum
{
	MAX_LOG = 8
};

class Contact;
class PhoneBook;

#ifndef DEBUG
# define DEBUG 0
#endif

#endif
