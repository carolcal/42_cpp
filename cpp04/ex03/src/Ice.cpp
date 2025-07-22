/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 11:09:38 by cayamash          #+#    #+#             */
/*   Updated: 2025/07/22 14:24:39 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

/* *********************** Constructors and Destructor ********************** */
Ice::Ice(void) : AMateria("ice") {};

Ice::Ice(const Ice &other) : AMateria(other)
{
	*this = other;
};

Ice::~Ice(void) {};

/* *************************** Assignment operator ************************** */
Ice& Ice::operator=(const Ice &other)
{
	(void)other;
	return *this;
}

/* **************************** Method Functions *************************** */
AMateria*	Ice::clone() const
{
	return new Ice(*this);
}

void		Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " 
		<< target.getName() << " *" << std::endl;
}
