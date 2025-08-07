/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 10:07:15 by cayamash          #+#    #+#             */
/*   Updated: 2025/08/07 11:47:39 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

/* *********************** Constructors and Destructor ********************** */
RPN::RPN(void) {};

RPN::RPN(const RPN &other) { *this = other; };

RPN::~RPN(void) {};

/* *************************** Assignment Operator ************************** */
RPN&	RPN::operator=(const RPN &other)
{
	if (this != &other)
		*this = other;
	return *this;
};

/* ***************************** Member Functions *************************** */
void	RPN::calculate(std::string expr)
{
	if (expr.length() == 0)
			throw std::invalid_argument("Please enter an expression.");
	for (unsigned long i = 0; i < expr.length(); i++)
	{
		if (expr[i] == '0')
			continue;
		if (isValidDigit(expr[i], expr[i + 1]))
		{
			_nums.push(expr[i] - '0');
		}
		else if (isValidOperator(expr[i]))
		{
			if (expr[i + 1] && !isspace(expr[i + 1]))
				throw std::invalid_argument("Items in expression must be separated with spaces.");
			makeOperation(expr[i]);
		}
		else if (!isspace(expr[i]))
			throw std::invalid_argument("Use only numbers between 0 and 9 and basic operators (+-*/).");
	}
	if (!_nums.top())
		throw std::invalid_argument("Invalid Expression.");
	std::cout << "Result: " << _nums.top() << std::endl;
};

bool	RPN::isValidDigit(char curr, char next)
{
	if (isdigit(curr))
	{
		if (next && !isspace(next) && isdigit(next))
			throw std::out_of_range("Numbers must be between 0 and 9.");
		if (next && !isspace(next) && isValidOperator(next))
			throw std::invalid_argument("Items in expression must be separated with spaces.");
		return true;
	}
	return false;
};

bool	RPN::isValidOperator(char op)
{
	if (op == '+' || op == '-' || op == '*' || op == '/')
		return true;
	return false;
};

void	RPN::makeOperation(char op)
{
	if (_nums.size() < 2)
		throw std::invalid_argument("Invalid Expression.");
	int b = _nums.top();
	_nums.pop();
	int a = _nums.top();
	_nums.pop();
	if (op == '+')		_nums.push(a + b);
	else if (op == '-')	_nums.push(a - b);
	else if (op == '*')	_nums.push(a * b);
	else				_nums.push(a / b);
};
