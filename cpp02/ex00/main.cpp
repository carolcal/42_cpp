/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 17:18:02 by cayamash          #+#    #+#             */
/*   Updated: 2025/07/16 14:09:03 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) 
{
    std::cout << PINK << "* Constructors *" << RESET << std::endl;
    Fixed a;
    Fixed b( a );
    Fixed c;
    std::cout << std::endl;

	std::cout << PINK << "* Assignment operator *" << RESET << std::endl;
    c = b;
    std::cout << std::endl;

	std::cout << PINK << "* Get Raw Bits *" << RESET << std::endl;
    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;
    std::cout << std::endl;

	std::cout << PINK << "* Set Raw Bits *" << RESET << std::endl;
    a.setRawBits(42); 
    std::cout << "setRawBits(42): " << a.getRawBits() << std::endl;
    std::cout << std::endl;
	
	std::cout << PINK << "* End *" << RESET << std::endl;
    return 0;
}
