/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 14:28:24 by cayamash          #+#    #+#             */
/*   Updated: 2025/07/19 16:07:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
    std::cout << PINK << "* Constructors *" << RESET << std::endl;
    ScavTrap anonimus;
    ScavTrap vilain("Vilain");
    ScavTrap hero(anonimus);

    std::cout << PINK << "* Set Name *" << RESET << std::endl;
    hero.setName("Hero");
    
    std::cout << PINK << "* Attack!!! *" << RESET << std::endl;
    vilain.attack("Hero");
    vilain.attack("Hero");
    vilain.attack("Hero");
    vilain.attack("Hero");
    hero.takeDamage(4 * vilain.getAttackDamage());
    hero.beRepaired(10);
    hero.attack("Vilain");
    vilain.takeDamage(hero.getAttackDamage());
    vilain.attack("Hero");
    vilain.attack("Hero");
    hero.takeDamage(2 * vilain.getAttackDamage());
    hero.attack("Vilain");
    vilain.guardGate();

     std::cout << PINK << "* Destructors *" << RESET << std::endl;
    return (0);
}