/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 15:07:40 by marvin            #+#    #+#             */
/*   Updated: 2025/07/21 15:07:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

/* *********************** Constructors and Destructor ********************** */
WrongCat::WrongCat(void) : WrongAnimal("Wrong Cat")
{
	std::cout << "WrongCat created!" << std::endl;
};

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
	std::cout << "Copied " << _type << " Animal to " << other._type << std::endl;
	*this = other;
};

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destroyed!" << std::endl;
};

/* *************************** Assignment operator ************************** */
WrongCat& WrongCat::operator=(const WrongCat &other)
{
	std::cout << "WrongCat assignment operator called" << std::endl;
	if (this != &other)
	{
		WrongAnimal::operator=(other);
	}
	return *this;
};

/* **************************** Method Functions *************************** */
void    WrongCat::makeSound(void) const
{
    std::cout << "Wrong Miau!" << std::endl;
};