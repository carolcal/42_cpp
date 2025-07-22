/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 15:06:29 by marvin            #+#    #+#             */
/*   Updated: 2025/07/21 15:06:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

/* *********************** Constructors and Destructor ********************** */
WrongAnimal::WrongAnimal(void) : _type("Wrong Generic") 
{
	std::cout << "WrongAnimal " << _type << " created!" << std::endl;
};

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
	std::cout << "WrongAnimal " << _type << " created!" << std::endl;
};

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	std::cout << "Copied " << _type << " WrongAnimal to " << other._type << std::endl;
	*this = other;
};

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal " << _type << " destroyed!" << std::endl;
};

/* *************************** Assignment operator ************************** */
WrongAnimal& WrongAnimal::operator=(const WrongAnimal &other)
{
	std::cout << "WrongAnimal assignment operator called" << std::endl;
	if (this != &other)
	{
		_type = other._type;
	}
	return *this;
};

/* **************************** Method Functions *************************** */
std::string WrongAnimal::getType(void) const
{
	return _type;
};

void    WrongAnimal::makeSound(void) const
{
	std::cout << "**Generic Wrong Sound**" << std::endl;
};