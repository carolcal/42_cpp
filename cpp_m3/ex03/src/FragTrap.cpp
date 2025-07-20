/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 12:08:50 by marvin            #+#    #+#             */
/*   Updated: 2025/07/20 12:08:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/* *********************** Constructors and Destructor ********************** */
FragTrap::FragTrap(void): ClapTrap()
{
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << _name << " FragTrap created!" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << name << " FragTrap created!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other): ClapTrap(other)
{
    *this = other;
    std::cout << "Copied " << _name << " FragTrap!" << std::endl;
}

FragTrap::~FragTrap(void)
{
    std::cout << "Fragtrap " << _name << " destroyed!" << std::endl;
}

/* *************************** Assignment operator ************************** */
FragTrap& FragTrap::operator=(const FragTrap &other)
{
    std::cout << "FragTrap Assignment operator called" << std::endl;
    if (this != &other)
    {
        ClapTrap::operator=(other);
    }
    return *this;
}

/* **************************** Method Functions *************************** */
void FragTrap::highFivesGuys(void)
{
    if (_hitPoints <= 0)
	{
		std::cout << "FragTrap " << _name << 
			" is dead!" << std::endl;
		return ;
	}
	if (_energyPoints <= 0)
	{
		std::cout << "FragTrap " << _name << 
			" has no energy for High Fives! :(" << std::endl;
		return ;
	}
    std::cout << "FragTrap " << _name << " is requesting a High Five!" << std::endl;
}