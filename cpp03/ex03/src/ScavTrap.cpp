/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 16:59:19 by cayamash          #+#    #+#             */
/*   Updated: 2025/07/20 15:57:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/* *********************** Constructors and Destructor ********************** */
ScavTrap::ScavTrap(void): ClapTrap()
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << _name << " ScavTrap created!" << std::endl;
};

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << name << " ScavTrap created!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
    *this = other;
    std::cout << "Copied " << _name << " ScavTrap!" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
    std::cout << "ScavTrap " << _name << " destroyed!" << std::endl;
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

/* **************************** Method Functions **************************** */
void	ScavTrap::attack(const std::string& target)
{
	if (_hitPoints <= 0)
	{
		std::cout << "ScavTrap " << _name << 
			" is dead!" << std::endl;
		return ;
	}
	if (_energyPoints <= 0)
	{
		std::cout << "ScavTrap " << _name << 
			" has no energy to attack!" << std::endl;
		return ;
	}
	_energyPoints--;
    std::cout << "ScavTrap " << _name << " attacks " << target 
		<< ", causing " << _attackDamage << " points of damage and now has "
		<< _energyPoints << " energy points!" << std::endl;
}

void ScavTrap::guardGate(void)
{
    if (_hitPoints <= 0)
	{
		std::cout << "ScavTrap " << _name << 
			" is dead!" << std::endl;
		return ;
	}
	if (_energyPoints <= 0)
	{
		std::cout << "ScavTrap " << _name << 
			" has no energy to guard gate!" << std::endl;
		return ;
	}
    std::cout << "ScavTrap " << _name << " is now in Gate keeper mode!" << std::endl;
}