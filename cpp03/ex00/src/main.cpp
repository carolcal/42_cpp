/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 14:28:24 by cayamash          #+#    #+#             */
/*   Updated: 2025/07/22 17:51:43 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    std::cout << PINK << "\n* Constructors *" << RESET << std::endl;
    ClapTrap anonimus;
    ClapTrap vilain("Vilain");
    ClapTrap hero(anonimus);

    std::cout << PINK << "\n* Assign Values *" << RESET << std::endl;
    hero.setName("Hero");
    hero.setHitPoints(7);
    hero.setEnergyPoints(1);
    hero.setAttackDamage(11);
    
    std::cout << PINK << "\n* Fight!!! *" << RESET << std::endl;
    hero.attack("Vilain");
    vilain.takeDamage(11);
    vilain.beRepaired(3);
    vilain.attack("Hero");
    hero.takeDamage(0);
    hero.attack("Vilain");

     std::cout << PINK << "\n* Destructors *" << RESET << std::endl;
    return (0);
}