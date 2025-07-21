/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:21:33 by marvin            #+#    #+#             */
/*   Updated: 2025/07/21 14:21:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/* *********************** Constructors and Destructor ********************** */
Animal::Animal(void) : _type("Generic") 
{
    std::cout << "Animal " << _type << " created!" << std::endl;
};

Animal::Animal(std::string type) : _type(type)
{
    std::cout << "Animal " << _type << " created!" << std::endl;
};

Animal::Animal(const Animal &other)
{
    std::cout << "Copied " << _type << " Animal to " << other._type << std::endl;
    *this = other;
};

Animal::~Animal(void)
{
    std::cout << "Animal " << _type << " destroyed!" << std::endl;
};

/* *************************** Assignment operator ************************** */
Animal& Animal::operator=(const Animal&other)
{
    std::cout << "Animal assignment operator called" << std::endl;
    if (this != &other)
    {
        _type = other._type;
    }
    return *this;
};

/* **************************** Method Functions *************************** */
std::string Animal::getType(void) const
{
    return _type;
};

void    Animal::makeSound(void) const
{
    std::cout << "**Generic Sound**" << std::endl;
};