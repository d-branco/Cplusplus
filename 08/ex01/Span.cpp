/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   Span.cpp                             :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/11/27 14:33:02      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/11/27 15:15:42     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include "Span.hpp"

///////////////////////////////////////////////////// Canonical Orthodox Form //
Span::Span(unsigned int ene) : ene_(ene)
{
	if (DEBUG)
	{
		std::cout << "==DEBUG== Span: Default Parametrized Constructor: N: "
				  << ene_ << "\n";
	}
}

Span::Span(const Span &other) : ene_(other.ene_), vec_(other.vec_)
{
	if (DEBUG)
	{
		std::cout << "==DEBUG== Span: Copy Constructor\n";
	}
	*this = other;
}

Span &Span::operator=(const Span &other)
{
	if (DEBUG)
	{
		std::cout << "==DEBUG== Span: Copy Operator Constructor\n";
	}
	if (this == &other)
	{
		return (*this);
	}
	ene_ = other.ene_;
	vec_ = other.vec_;

	return (*this);
}

Span::~Span()
{
	if (DEBUG)
	{
		std::cout << "==DEBUG== Span: Destructor\n";
	}
}

///////////////////////////////////////////////////////////////////// Getters //
///////////////////////////////////////////////////////////////////// Setters //
/////////////////////////////////////////////////////////////////// Functions //
void Span::addNumber(int nbr)
{
	if (DEBUG)
	{
		std::cout << "==DEBUG== Span: addNumber(" << nbr << ") trying...";
	}
	try
	{
		if (vec_.size() >= ene_)
		{
			throw std::exception();
		}
		vec_.push_back(nbr);
		if (DEBUG)
		{
			std::cout << " SUCCESS! Vector size: " << vec_.size() << "\n";
		}
	}
	catch (const std::exception &e)
	{
		if (DEBUG)
		{
			std::cout << "\n";
		}
		std::cout << "Error:\n  Maximum INT stored already (" << ene_ << ")\n";
	}
}