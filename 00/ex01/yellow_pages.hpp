/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   yellow_pages.hpp                     :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/08/28 19:26:28      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/08/28 19:27:27     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#ifndef YELLOW_PAGES_H
#define YELLOW_PAGES_H

#include <cstdlib>
#include <iomanip> //set width with std::setw(size)
#include <iostream>

#include "Contact.hpp"
#include "PhoneBook.hpp"

enum
{
	FALSE	= 0,
	TRUE	= 1,
	MAX_LOG = 8
};

#ifndef DEBUG
# define DEBUG 0
#endif

#endif
