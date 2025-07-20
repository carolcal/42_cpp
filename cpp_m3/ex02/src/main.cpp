/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 14:28:24 by cayamash          #+#    #+#             */
/*   Updated: 2025/07/20 12:29:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
    std::cout << PINK << "* Constructors *" << RESET << std::endl;
    FragTrap anonimus;
    ScavTrap vilain("Vilain");
    FragTrap hero(anonimus);

    std::cout << PINK << "* Assign Values *" << RESET << std::endl;
    hero.setName("Hero");
    hero.setHitPoints(19);
    hero.setEnergyPoints(2);
    hero.setAttackDamage(11);
    
    std::cout << PINK << "* Attack!!! *" << RESET << std::endl;
    vilain.attack("Hero");
    hero.takeDamage(vilain.getAttackDamage());
    hero.beRepaired(3);
    hero.highFivesGuys();
    vilain.attack("Hero");
    hero.takeDamage(vilain.getAttackDamage());
    hero.attack("Vilain");
    vilain.guardGate();

     std::cout << PINK << "* Destructors *" << RESET << std::endl;
    return (0);
}