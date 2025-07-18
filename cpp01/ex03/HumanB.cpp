/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 15:02:22 by cayamash          #+#    #+#             */
/*   Updated: 2025/07/11 17:02:29 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(const std::string& name): _name(name), _weapon(NULL) {};

void HumanB::attack()
{
    std::cout << _name << " attacks with their ";
	if (_weapon)
        std::cout << _weapon->getType() << "!" << std::endl;
    else
        std::cout << "bare fists!" << std::endl;
}

void	HumanB::setWeapon(Weapon& weapon)
{
	_weapon = &weapon;
}