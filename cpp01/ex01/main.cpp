/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 09:43:39 by cayamash          #+#    #+#             */
/*   Updated: 2025/07/15 10:51:13 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "Usage: ./zombieHorde <name>" << std::endl;
        return (1);
    }
    
    std::cout << "------------------------------------" << std::endl;
    
    std::cout << "Creating 10 zombies named " << argv[1] << std::endl;
    Zombie* horde = zombieHorde(10, argv[1]);
    
    std::cout << "------------------------------------" << std::endl;
    
    std::cout << "Anouncing 10 zombies named " << argv[1] << std::endl;
    for (int i = 0; i < 10; i++)
    {
        horde[i].announce();
    }
    
    std::cout << "------------------------------------" << std::endl;
    
    std::cout << "Destroying 10 zombies named " << argv[1] << std::endl;
    
    delete []horde;

    return (0);
}