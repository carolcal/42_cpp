/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 10:05:34 by cayamash          #+#    #+#             */
/*   Updated: 2025/07/11 13:00:58 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
    std::cout << "Zombie with no name has awaken!" << std::endl;
}

Zombie::Zombie(const std::string& name) : _name(name)
{
    std::cout << "Zombie " << name << " has awaken!" <<std::endl;
}

Zombie::~Zombie()
{
    std::cout << "Zombie " << _name << " destroyed!" << std::endl;
}

void Zombie::announce(void) const
{
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(const std::string& name)
{
    _name = name;
    std::cout << "Gave name " << name << " to zombie!" << std::endl;
}