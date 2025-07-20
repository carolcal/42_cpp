/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 13:33:16 by cayamash          #+#    #+#             */
/*   Updated: 2025/07/20 11:38:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/* *********************** Constructors and Destructor ********************** */
ClapTrap::ClapTrap(void) : _name("Anonimus"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "Anonimus ClapTrap created!" << std::endl;
};

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
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
    std::cout << "ClapTrap Assignment operator called" << std::endl;
    if (this != &other)
	{
        this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
    return *this;
}

/* **************************** Method Functions *************************** */
void	ClapTrap::attack(const std::string& target)
{
	if (_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << 
			" is dead!" << std::endl;
		return ;
	}
	if (_energyPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << 
			" has no energy to attack!" << std::endl;
		return ;
	}
	_energyPoints--;
    std::cout << "ClapTrap " << _name << " attacks " << target 
		<< ", causing " << _attackDamage << " points of damage and now has "
		<< _energyPoints << " energy points!" << std::endl;
}
void	ClapTrap::takeDamage(unsigned int amount)
{
    _hitPoints -= amount;
    std::cout << "ClapTrap " << _name << " takes " << amount 
		<< " points of damage and now has "
		<< _hitPoints << " hit points!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	_energyPoints--;
	_hitPoints += amount;
	std::cout << "ClapTrap " << _name << " repairs " << amount
		<< " hit points and now has " << _hitPoints
		<< " hit points and " << _energyPoints
		<< " energy points!" << std::endl;
}

/* ***************************** Get Functions **************************** */
std::string	ClapTrap::getName(void)
{
	return _name;
}

int			ClapTrap::getHitPoints(void)
{
	return _hitPoints;
}

int			ClapTrap::getEnergyPoints(void)
{
	return _energyPoints;
}

int			ClapTrap::getAttackDamage(void)
{
	return _attackDamage;
}

/* ***************************** Set Functions **************************** */
void	ClapTrap::setName(std::string name)
{
	std::cout << _name << " ClapTrap is now named " << name << std::endl;
	_name = name;
}

void	ClapTrap::setHitPoints(int value)
{
	std::cout << _name << " ClapTrap now has " << value << " hit points!" << std::endl;
	_hitPoints = value;
}

void	ClapTrap::setEnergyPoints(int value)
{
	std::cout << _name << " ClapTrap now has " << value << " energy points!" << std::endl;
	_energyPoints = value;
}

void	ClapTrap::setAttackDamage(int value)
{
	std::cout << _name << " ClapTrap now has " << value << " attack points!" << std::endl;
	_attackDamage = value;
}
