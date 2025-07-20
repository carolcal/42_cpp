/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 14:28:24 by cayamash          #+#    #+#             */
/*   Updated: 2025/07/20 16:00:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
    std::cout << PINK << "\n* Constructors *" << RESET << std::endl;
    ScavTrap anonimus;
    ScavTrap vilain("Vilain");
    ScavTrap hero(anonimus);

    std::cout << PINK << "\n* Assign Values *" << RESET << std::endl;
    hero.setName("Hero");
    hero.setHitPoints(19);
    hero.setEnergyPoints(2);
    hero.setAttackDamage(11);
    
    std::cout << PINK << "\n* Fight!!! *" << RESET << std::endl;
    vilain.attack("Hero");
    hero.takeDamage(vilain.getAttackDamage());
    hero.beRepaired(3);
    hero.attack("Vilain");
    vilain.takeDamage(hero.getAttackDamage());
    vilain.attack("Hero");
    hero.takeDamage(vilain.getAttackDamage());
    hero.attack("Vilain");
    vilain.guardGate();

     std::cout << PINK << "\n* Destructors *" << RESET << std::endl;
    return (0);
}