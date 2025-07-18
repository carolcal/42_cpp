/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 13:33:16 by cayamash          #+#    #+#             */
/*   Updated: 2025/07/18 16:51:22 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/* *********************** Constructors and Destructor ********************** */
ClapTrap::ClapTrap(void) : _name("Anonimus"), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "Anonimus ClapTrap created!" << std::endl;
};

ClapTrap::ClapTrap(std::string name) : _name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << name << " ClapTrap created!" << std::endl;
};

ClapTrap::ClapTrap(const ClapTrap &other)
{
	*this = other;
    std::cout << "Copied " << _name << " ClapTrap!" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
    std::cout << "ClapTrap " << _name << " destroyed!" << std::endl;
}

/* *************************** Assignment operator ************************** */
ClapTrap& ClapTrap::operator=(const ClapTrap &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
	{
        this->_name = other._name;
		this->hitPoints = other.hitPoints;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
	}
    return *this;
}

/* **************************** Method Functions *************************** */
void	ClapTrap::attack(const std::string& target)
{
	if (hitPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << 
			" is dead!" << std::endl;
		return ;
	}
	if (energyPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << 
			" has no energy to attack!" << std::endl;
		return ;
	}
	energyPoints--;
    std::cout << "ClapTrap " << _name << " attacks " << target 
		<< ", causing " << attackDamage << " points of damage and now has "
		<< energyPoints << " energy points!" << std::endl;
}
void	ClapTrap::takeDamage(unsigned int amount)
{
    hitPoints -= amount;
    std::cout << "ClapTrap " << _name << " takes " << amount 
		<< " points of damage and now has "
		<< hitPoints << " hit points!" << std::endl;
}

void	ClapTrap::beRapaired(unsigned int amount)
{
	energyPoints--;
	hitPoints += amount;
	std::cout << "ClapTrap " << _name << " repairs " << amount
		<< " hit points and now has " << hitPoints
		<< " hit points and " << energyPoints
		<< " energy points!" << std::endl;
}

void	ClapTrap::setName(std::string name)
{
	std::cout << _name << " ClapTrap is now named " << name << std::endl;
	_name = name;
}