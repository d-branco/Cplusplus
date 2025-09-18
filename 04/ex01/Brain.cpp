/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   Brain.cpp                            :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/09/18 08:11:59      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/09/18 08:56:38     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include "Brain.hpp"

///////////////////////////////////////////////////// Canonical Orthodox Form //
Brain::Brain() : ideas_(new std::string[100])
{
	ideas_[0] = "Do I think?\n";
	for (size_t index = 1; index < 100; index++)
	{
		ideas_[index] = "";
	}
    std::cout << "     └─ Brain: Default Constructor: Memory for 100 strings "
                 "allocated.\n";
}

Brain::Brain(const Brain &other) : ideas_(new std::string[100])
{
    std::cout << "     └─ Brain copy constructed. "
              << "Memory for 100 strings allocated.\n";
    for (size_t i = 0; i < 100; ++i)
    {
        ideas_[i] = other.ideas_[i];
    }
}

Brain &Brain::operator=(const Brain &other)
{
    if (this == &other)
    {
        return (*this);
    }

    delete[] ideas_;
    ideas_ = new std::string[100];
    std::cout << "     └─ Brain copy operator constructed. "
              << "Memory for 100 strings allocated.\n";
    for (size_t i = 0; i < 100; ++i)
    {
        ideas_[i] = other.ideas_[i];
    }
    return (*this);
}

Brain::~Brain()
{
    delete[] this->ideas_;
    std::cout << " ├─ Brain: Destructor: 100 strinds deleted.\n";
}

/////////////////////////////////////////////////////////////////// Functions //
std::string &Brain::operator[](size_t index)
{
    return this->ideas_[index];
}

const std::string &Brain::operator[](size_t index) const
{
    return this->ideas_[index];
}

