/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 09:43:39 by cayamash          #+#    #+#             */
/*   Updated: 2025/07/11 11:49:32 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump( std::string name );

int main()
{

    std::cout << "------------------------------------" << std::endl;
    
    std::cout << "Creating zombie on the heap memory" << std::endl;
    Zombie* heapZombie = newZombie("Heap");
    heapZombie->announce();
    std::cout << "Destroying zombie on the heap memory" << std::endl;
    delete heapZombie;
    
    std::cout << "------------------------------------" << std::endl;
    
    std::cout << "Creating zombie on the stack memory" << std::endl;
    randomChump("Stack");
    std::cout << "Zombie was automaticaly destroyed!" << std::endl;

    std::cout << "------------------------------------" << std::endl;

    return (0);
}