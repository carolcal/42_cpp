/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 16:05:34 by marvin            #+#    #+#             */
/*   Updated: 2025/07/21 16:05:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

/* *********************** Constructors and Destructor ********************** */
Brain::Brain(void)
{
	std::cout << "Brain created!" << std::endl;
}

Brain::Brain(const Brain &other)
{
	std::cout << "Copied Brain!" << std::endl;
	*this = other;
}

Brain::~Brain(void)
{
	std::cout << "Brain destroyed!" << std::endl;
}

/* *************************** Assignment operator ************************** */
Brain& Brain::operator=(const Brain &other)
{
	std::cout << "Brain assignment operator called" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < _maxIdeas; i++)
		{
			_ideas[i] = other._ideas[i];
		}
	}
	return *this;
}

/* **************************** Method Functions *************************** */
std::string Brain::getIdea(int index)
{
	if (index < _maxIdeas)
		return _ideas[index];
	return "Invalid Index";
}

void    Brain::setIdea(int index, std::string idea)
{
	if (index < _maxIdeas)
	{
		_ideas[index] = idea;
		std::cout << "Setted idea " << idea << " in index " << index << std::endl;
	}
	else
		std::cout << "Invalid Index" << std::endl;
}