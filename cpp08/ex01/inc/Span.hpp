/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 10:00:24 by cayamash          #+#    #+#             */
/*   Updated: 2025/07/30 14:53:01 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iostream>
#include <algorithm>


class Span
{
	private:
		unsigned int		_size;
		std::vector<int>	_numbers;

		Span(void);

	public:
		/* ***** Constructors and Destructor **** */
		Span(unsigned int n);
		Span(const Span &other);
		~Span(void);

		/* ************* Operators ************* */
		Span& operator=(const Span &other);

		/* ********** Member Functions ********* */
		void			addNumber(int number);
		int				shortestSpan(void);
		int				longestSpan(void);
		unsigned int	size(void);
		void			populate(unsigned int n);

		template <typename iterator>
		void	addRange(iterator begin, iterator end)
		{
			if (std::distance(begin, end) + _numbers.size() > _size)
				throw std::overflow_error("Error: Span is full!");
			_numbers.insert(_numbers.end(), begin, end);
		}
};

#endif