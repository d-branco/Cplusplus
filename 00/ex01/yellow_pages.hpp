/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   yellow_pages.hpp                     :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/08/28 21:39:41      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/08/30 12:39:55     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#ifndef YELLOW_PAGES_H
#define YELLOW_PAGES_H

#include <csignal>
#include <cstdlib>
#include <iomanip> //set width with std::setw(size)
#include <iostream>

enum
{
	MAX_LOG = 3
};

#include "Contact.hpp"
#include "PhoneBook.hpp"

class Contact;
class PhoneBook;

#ifndef DEBUG
# define DEBUG 0
#endif

#endif
