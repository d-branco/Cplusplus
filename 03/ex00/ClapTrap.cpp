/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   ClapTrap.cpp                         :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/09/14 14:21:28      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/09/14 14:56:12     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// class ClapTrap
// {
// 	private:
// 		std::string			name_;
// 		unsigned int		hit_;
// 		unsigned int		energy_;
// 		unsigned int		attack_;

// 	public:
// 		void				attack(const std::string& target);
// 		void				takeDamage(unsigned int amount);
// 		void				beRepaired(unsigned int amount);
// };
ClapTrap::ClapTrap(std::string name) :
	name_(name),
	hit_(10),
	energy_(10),
	attack_(0)
{
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
}

ClapTrap::~ClapTrap()
{
}

void attack(const std::string &target)
{
}

void takeDamage(unsigned int amount)
{
}

void beRepaired(unsigned int amount)
{
}
