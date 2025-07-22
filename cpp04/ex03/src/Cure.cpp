/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 11:18:19 by cayamash          #+#    #+#             */
/*   Updated: 2025/07/22 14:08:40 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

/* *********************** Constructors and Destructor ********************** */

Cure::Cure(void) : AMateria("cure") {};

Cure::Cure(const Cure &other) : AMateria(other)
{
	*this = other;
};

Cure::~Cure(void) {};

/* *************************** Assignment operator ************************** */
Cure& Cure::operator=(const Cure &other)
{
	(void)other;
	return *this;
}

/* **************************** Method Functions *************************** */
AMateria*	Cure::clone() const
{
	return new Cure(*this);
}

void		Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() 
        << "’s wounds *" << std::endl;
}