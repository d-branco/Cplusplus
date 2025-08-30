/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   yellow_pages.hpp                     :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/08/30 15:46:08      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/08/30 18:04:57     #########  #########  ###      ###      */
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
	MAX_LOG		 = 8,
	COLUMN_WIDTH = 10
};

#include "Contact.hpp"
#include "PhoneBook.hpp"

class Contact;
class PhoneBook;

#ifndef DEBUG
# define DEBUG 0
#endif

#endif
