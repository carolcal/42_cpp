/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:31:01 by marvin            #+#    #+#             */
/*   Updated: 2025/07/21 14:31:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/* *********************** Constructors and Destructor ********************** */
Dog::Dog(void) : Animal("Dog")
{
	std::cout << "Dog created!" << std::endl;
};

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << "Copied " << _type << " Animal to " << other._type << std::endl;
	*this = other;
};

Dog::~Dog(void)
{
	std::cout << "Dog destroyed!" << std::endl;
};

/* *************************** Assignment operator ************************** */
Dog& Dog::operator=(const Dog&other)
{
	std::cout << "Dog assignment operator called" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
	}
	return *this;
};

/* **************************** Method Functions *************************** */
void    Dog::makeSound(void) const
{
    std::cout << "AuAu!" << std::endl;
};