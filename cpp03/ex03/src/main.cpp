/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 14:28:24 by cayamash          #+#    #+#             */
/*   Updated: 2025/07/20 16:00:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

//FALTA FAZER O MAIN!!!
int main(void)
{
    std::cout << PINK << "\n* Constructors *" << RESET << std::endl;
    DiamondTrap anonimus;
    DiamondTrap vilain("Vilain");
    DiamondTrap hero(anonimus);

    std::cout << PINK << "\n* Assign Values *" << RESET << std::endl;
    hero.setName("Hero");
    hero.setHitPoints(20);
    hero.setEnergyPoints(2);
    hero.setAttackDamage(11);
    
    std::cout << PINK << "\n* Who Am I??? *" << RESET << std::endl;
    anonimus.whoAmI();
    vilain.whoAmI();
    hero.whoAmI();

    std::cout << PINK << "\n* Fight!!! *" << RESET << std::endl;
    vilain.attack("Hero");
    hero.takeDamage(vilain.getAttackDamage());
    hero.beRepaired(12);
    hero.highFivesGuys();
    vilain.attack("Hero");
    hero.takeDamage(vilain.getAttackDamage());
    hero.attack("Vilain");
    vilain.guardGate();

     std::cout << PINK << "\n* Destructors *" << RESET << std::endl;
    return (0);
}