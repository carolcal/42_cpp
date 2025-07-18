/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 14:28:24 by cayamash          #+#    #+#             */
/*   Updated: 2025/07/18 16:50:17 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    std::cout << PINK << "* Constructors *" << RESET << std::endl;
    ClapTrap anonimus;
    ClapTrap vilain("Vilain");
    ClapTrap hero(anonimus);

    std::cout << PINK << "* Set Name *" << RESET << std::endl;
    hero.setName("Hero");
    
    std::cout << PINK << "* Attack!!! *" << RESET << std::endl;
    vilain.attack("Hero");
    hero.takeDamage(7);
    hero.attack("Vilain");
    vilain.takeDamage(5);
    vilain.attack("Hero");
    hero.takeDamage(5);
    hero.beRapaired(3);
    hero.attack("Vilain");
    vilain.takeDamage(6);
    vilain.attack("Hero");

     std::cout << PINK << "* Destructors *" << RESET << std::endl;
    return (0);
}