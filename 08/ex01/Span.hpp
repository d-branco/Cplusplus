/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   Span.hpp                             :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/11/27 14:33:02      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/11/30 11:42:37     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#ifndef DEBUG
# define DEBUG false
#endif

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

class Span
{
  private:
	unsigned int	 ene_;
	std::vector<int> vec_;

  public:
	///////////////////////////////////////////////// Canonical Orthodox Form //
	Span(unsigned int ene_);
	Span(const Span &other);
	Span &operator=(const Span &other);
	~Span();

	///////////////////////////////////////////////////////////////// Getters //
	///////////////////////////////////////////////////////////////// Setters //
	/////////////////////////////////////////////////////////////// Functions //
	void		 addNumber(int nbr);

	unsigned int shortestSpan();
	unsigned int longestSpan();

	void		 fill_with_value(int value, unsigned int count);

	void		 printVector();
};

#endif
