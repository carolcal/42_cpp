/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 13:21:53 by cayamash          #+#    #+#             */
/*   Updated: 2025/08/01 10:01:23 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/* *********************** Constructors and Destructor ********************** */
Span::Span(void) : _size(0) {};

Span::Span(unsigned int n) : _size(n) {};

Span::Span(const Span &other) : _size(other._size) 
{
	_numbers = other._numbers;
};

Span::~Span(void) {};

/* *************************** Assignment Operator ************************** */
Span& Span::operator=(const Span &other)
{
	if (this != &other)
	{
		_size = other._size;
		for (unsigned int i = 0; i < _size; i++)
			_numbers[i] = other._numbers[i];
	}
	return *this;
}

/* ***************************** Member Functions *************************** */
void	Span::addNumber(int number)
{
	if (_numbers.size() < _size)
		_numbers.push_back(number);
	else
		throw std::overflow_error("Error: Span is full!");
}
int		Span::shortestSpan(void)
{
	if (_numbers.size() < 2)
		throw std::length_error("Error: Not enought numbers to get span.");
	
	std::vector<int> sorted = _numbers;
	std::sort(_numbers.begin(), _numbers.end());
	
	int minRange = _numbers[1] - _numbers[0];
	if (_numbers.size() > 2)
	{
		for (unsigned int i = 2; i < _numbers.size(); i++)
		{
			int currRange = _numbers[i] - _numbers[i - 1];
			if (currRange < minRange)
				minRange = currRange;
		}
	}
	return minRange;
}
int		Span::longestSpan(void)
{
	if (_numbers.size() < 2)
		throw std::length_error("Error: Not enougth numbers to get span.");

	std::vector<int> sorted = _numbers;
	std::sort(_numbers.begin(), _numbers.end());
	int size = _numbers.size();
	int	maxRange = _numbers[size - 1] - _numbers[0];
	return maxRange;
}

unsigned int Span::size(void)
{
	return _size;
}

void	Span::populate(unsigned int n)
{
	std::vector<int> temp;
	for (unsigned int i = 0; i < n; i++)
	{
		temp.push_back(std::rand());
	}
	addRange(temp.begin(), temp.end());
}
