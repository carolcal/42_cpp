/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 14:52:27 by cayamash          #+#    #+#             */
/*   Updated: 2025/07/11 17:02:23 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(const std::string& name, Weapon& weapon): _name(name), _weapon(&weapon) {};

void HumanA::attack()
{
    std::cout << _name << " attacks with their ";
    if (_weapon)
        std::cout << _weapon->getType() << "!" << std::endl;
    else
        std::cout << "bare fists!" << std::endl;
}