/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   RPN.hpp                              :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/12/02 20:26:00      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/12/21 12:25:14     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>

#ifdef DEBUG
# define dprint(msg) std::cout << "==DEBUG== " << msg << "\n"
#else
# define dprint(msg) ((void) 0)
#endif

class RPN
{
  private:
	std::string stack_to_string(std::stack<int> polish);

  public:
	///////////////////////////////////////////////// Canonical Orthodox Form //
	RPN();
	RPN(const RPN &other);
	RPN &operator=(const RPN &other);
	~RPN();

	///////////////////////////////////////////////////////////////// Getters //
	///////////////////////////////////////////////////////////////// Setters //
	/////////////////////////////////////////////////////////////// Functions //
	int run(char *str);
};

#endif
