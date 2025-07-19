/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 16:59:19 by cayamash          #+#    #+#             */
/*   Updated: 2025/07/19 18:27:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/* *********************** Constructors and Destructor ********************** */
ScavTrap::ScavTrap(void): ClapTrap()
{
    setHitPoints(100);
    setEnergyPoints(50);
    setAttackDamage(20);
    std::cout << "Anonimus ScavTrap created!" << std::endl;
};

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    setHitPoints(100);
    setEnergyPoints(50);
    setAttackDamage(20);
    std::cout << name << " ScavTrap created!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
    *this = other;
    std::cout << "Copied " << getName() << " ScavTrap!" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
    std::cout << "ScavTrap " << getName() << " destroyed!" << std::endl;
}

/* *************************** Assignment operator ************************** */
ScavTrap& ScavTrap::operator=(const ScavTrap &other)
{
    std::cout << "ScavTrap Assignment operator called" << std::endl;
    if (this != &other)
    {
        ClapTrap::operator=(other);
    }
    return *this;
}

/* **************************** Method Functions *************************** */
void	ScavTrap::attack(const std::string& target)
{
	if (getHitPoints() <= 0)
	{
		std::cout << "ScavTrap " << getName() << 
			" is dead!" << std::endl;
		return ;
	}
	if (getEnergyPoints() <= 0)
	{
		std::cout << "ScavTrap " << getName() << 
			" has no energy to attack!" << std::endl;
		return ;
	}
	setEnergyPoints(getEnergyPoints() - 1);
    std::cout << "ScavTrap " << getName() << " attacks " << target 
		<< ", causing " << getAttackDamage() << " points of damage and now has "
		<< getEnergyPoints() << " energy points!" << std::endl;
}

void ScavTrap::guardGate(void)
{
    std::cout << "ScavTrap " << getName() << " is now in Gate keeper mode!" << std::endl;
}