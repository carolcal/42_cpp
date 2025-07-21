/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:45:02 by marvin            #+#    #+#             */
/*   Updated: 2025/07/21 14:45:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/* *********************** Constructors and Destructor ********************** */
Cat::Cat(void) : Animal("Cat")
{
	std::cout << "Cat created!" << std::endl;
};

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << "Copied " << _type << " Animal to " << other._type << std::endl;
	*this = other;
};

Cat::~Cat(void)
{
	std::cout << "Cat destroyed!" << std::endl;
};

/* *************************** Assignment operator ************************** */
Cat& Cat::operator=(const Cat&other)
{
	std::cout << "Cat assignment operator called" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
	}
	return *this;
};

/* **************************** Method Functions *************************** */
void    Cat::makeSound(void) const
{
    std::cout << "Miau!" << std::endl;
};