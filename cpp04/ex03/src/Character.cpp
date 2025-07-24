/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:23:04 by cayamash          #+#    #+#             */
/*   Updated: 2025/07/24 09:42:56 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

/* *********************** Constructors and Destructor ********************** */
Character::Character(void) : _name("Anonimus") 
{
	initArrays();
	std::cout << "Created Anonimus Character." << std::endl;
};

Character::Character(std::string name) : _name(name) 
{
	initArrays();
	std::cout << "Created " << name << " Character." << std::endl;
};

Character::Character(const Character &other) 
{
	initArrays();
	*this = other;
	std::cout << "Copied new Character." << std::endl;
};

Character::~Character(void) 
{
	for (int i = 0; i < _inventorySize; i++)
		delete _inventory[i];
	for (int j = 0; j < _floorSize; j++)
		delete _floor[j];
	std::cout << "Destroyed " << _name << " Character" << std::endl;
};

/* *************************** Assignment operator ************************** */
Character& Character::operator=(const Character &other)
{
	std::cout << "Character assignment operator called." << std::endl;
	if (this != &other)
	{
		_name = other._name;
		for (int i = 0; i < _inventorySize; i++)
		{
			delete _inventory[i];
			_inventory[i] = NULL;
			if (other._inventory[i])
				_inventory[i] = other._inventory[i]->clone();
		}
		for (int j = 0; j < _floorSize; j++)
		{
			delete _floor[j];
			_floor[j] = NULL;
			if (other._floor[j])
				_floor[j] = other._floor[j]->clone();
		}
	}
	return *this;
};

/* **************************** Method Functions *************************** */
std::string const& Character::getName(void) const { return _name; };

void    Character::equip(AMateria *m)
{
	if (!m)
	{
		std::cout << "Tried to equip a NULL materia!" << std::endl;
		return ;
	}
	for (int i = 0; i < _inventorySize; i++)
	{
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m;
			std::cout << "Type " << m->getType() << " saved on index "
				<< i << " of the inventory." << std::endl;
			break ;
		}
		if (i == _inventorySize - 1)
		{
			std::cout << "Inventory is full!" << std::endl;
			delete m;
		}
	}
}

void    Character::unequip(int idx)
{
	if (idx >= 0 && idx < _inventorySize)
	{
		if (dropFloor(_inventory[idx]))
		{
			std::cout << "Unequiped Materia " << _inventory[idx]->getType() << std::endl;
			_inventory[idx] = NULL;
			return ;
		}
		std::cout << "Can't unequip. Floor is full!" << std::endl;
		return ;
	}
	std::cout << "Invalid Index!" << std::endl;
}

void    Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4)
	{
		if (_inventory[idx])
		{
			_inventory[idx]->use(target);
			return ;
		}
		std::cout << "There is no Materia in the slot " << idx << " of the inventory." << std::endl;
		return ;
	}
	std::cout << "Index out of range of the inventory." << std::endl;
	
}

bool    Character::dropFloor(AMateria* m)
{
	for(int i = 0; i < _floorSize; i++)
	{
		if (_floor[i] == NULL)
		{
			_floor[i] = m;
			return true ;
		}
	}
	return false;
}

void	Character::initArrays(void)
{
	for (int i = 0; i < _inventorySize; i++)
		_inventory[i] = NULL;
	for (int j = 0; j < _floorSize; j++)
		_floor[j] = NULL;
}