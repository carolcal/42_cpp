/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 13:57:39 by marvin            #+#    #+#             */
/*   Updated: 2025/07/20 13:57:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

/* *********************** Constructors and Destructor ********************** */
DiamondTrap::DiamondTrap(void) :
	ClapTrap("Anonimus_clap_name"), 
	ScavTrap(), 
	FragTrap(), 
	_name("Anonimus")
{
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	std::cout << "Anonimus DiamondTrap created!" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : 
	ClapTrap(name + "_clap_name"), 
	ScavTrap(), 
	FragTrap(), 
	_name(name)
{
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	std::cout << name << " DiamondTrap created!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other): 
	ClapTrap(other._name + "_clap_name"), 
	ScavTrap(other), 
	FragTrap(other)
{
	*this = other;
	std::cout << "Copied " << _name << " DiamondTrap!" << std::endl;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap " << _name << " destroyed!" << std::endl;
}

/* *************************** Assignment operator ************************** */
DiamondTrap& DiamondTrap::operator=(const DiamondTrap &other)
{
	std::cout << "DiamondTrap Assignment operator called" << std::endl;
	if (this != &other)
	{
		ClapTrap::operator=(other);
		this->_name = other._name;
	}
	return *this;
}

/* **************************** Method Functions *************************** */
void	DiamondTrap::whoAmI(void)
{
	std::cout << _name << " DiamondTrap at home is "
	<< ClapTrap::getName() << " ClapTrap."<< std::endl;
}

/* ***************************** Set Functions **************************** */
void	DiamondTrap::setName(std::string name)
{
	std::cout << _name << " DiamondTrap is now named " << name
	<< " and at home he is now ClapTrap named " << name << "_clap_name" << std::endl;
	_name = name;
	ClapTrap::setName(name + "_clap_name");
}