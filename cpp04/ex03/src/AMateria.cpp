/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 10:49:39 by cayamash          #+#    #+#             */
/*   Updated: 2025/07/22 11:29:04 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

/* *********************** Constructors and Destructor ********************** */
AMateria::AMateria(void) : _type("None") {};

AMateria::AMateria(std::string const &type) : _type(type) {};

AMateria::AMateria(const AMateria &other)
{
    *this = other;
}

AMateria::~AMateria(void) {};

/* *************************** Assignment operator ************************** */
AMateria& AMateria::operator=(const AMateria &other)
{
    (void)other;
    return *this;
};

/* **************************** Method Functions *************************** */
std::string const& AMateria::getType() const
{
    return _type;
}

void    AMateria::use(ICharacter& target)
{
    std::cout << "Uses " << _type << " Materia in target " 
        << target.getName() << std::endl;
}