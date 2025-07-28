/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 09:34:06 by cayamash          #+#    #+#             */
/*   Updated: 2025/07/28 17:24:06 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

# define RESET	"\033[0m"
# define PINK	"\033[35m"

int main( void )
{
	std::cout << PINK << "* Defining a and b *" << RESET << std::endl;
	int a = 2;
	int b = 3;
	std::cout << "a = " << a << ", b = " << b << std::endl;
	
	std::cout << PINK << "* Swaping a and b *" << RESET << std::endl;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;

	std::cout << PINK << "* Getting min and max *" << RESET << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::cout << PINK << "\n* Defining c and d *" << RESET << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	std::cout << "c = " << c << ", d = " << d << std::endl;

	std::cout << PINK << "* Swaping c and d *" << RESET << std::endl;
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;

	std::cout << PINK << "* Getting min and max *" << RESET << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	return 0;
}