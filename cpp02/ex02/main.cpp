/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 17:18:02 by cayamash          #+#    #+#             */
/*   Updated: 2025/07/16 16:56:18 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


int main( void )
{

	Fixed a(4);
	Fixed b(4.20f);
	Fixed c(4.0f);
	Fixed d;
	Fixed const e( Fixed(5.05f) / Fixed(2));
	Fixed const f( Fixed(5.05f) * Fixed(2) );
	std::cout << std::endl;

	std::cout << PINK << "* Values *" << RESET << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "c: " << c << std::endl;
	std::cout << "d: " << d << std::endl;
	std::cout << "e: " << e << std::endl;
	std::cout << "f: " << f << std::endl;
	std::cout << std::endl;

	std::cout << PINK << "* Comparing numbers *" << RESET << std::endl;
	std::cout << "a < b : " << (a < b) << std::endl;
	std::cout << "b < a : " << (b < a) << std::endl;
	std::cout << "a < c : " << (a < c) << std::endl;
	std::cout << "a > b : " << (a > b) << std::endl;
	std::cout << "b > a : " << (b > a) << std::endl;
	std::cout << "a > c : " << (a > c) << std::endl;
	std::cout << "a <= b: " << (a <= b) << std::endl;
	std::cout << "b <= a: " << (b <= a) << std::endl;
	std::cout << "a <= c: " << (a <= c) << std::endl;
	std::cout << "a >= b: " << (a >= b) << std::endl;
	std::cout << "b >= a: " << (b >= a) << std::endl;
	std::cout << "a >= c: " << (a >= c) << std::endl;
	std::cout << "a == b: " << (a == b) << std::endl;
	std::cout << "b == a: " << (b == a) << std::endl;
	std::cout << "a == c: " << (a == c) << std::endl;
	std::cout << "a != b: " << (a != b) << std::endl;
	std::cout << "b != a: " << (b != a) << std::endl;
	std::cout << "a != c: " << (a != c) << std::endl;
	std::cout << std::endl;

	std::cout << PINK << "* Calculating numbers *" << RESET << std::endl;
	std::cout << "a + b: " << (a + b) << std::endl;
	std::cout << "a - b: " << (a - b) << std::endl;
	std::cout << "a * b: " << (a * b) << std::endl;
	std::cout << "a / b: " << (a / b) << std::endl;
	std::cout << "a / d: " << (a / d) << std::endl;
	std::cout << "d / a: " << (d / a) << std::endl;
	std::cout << std::endl;

	std::cout << PINK << "* Incrementing numbers *" << RESET << std::endl;
	std::cout << "d: " << d << std::endl;
	std::cout << "d: " << ++d << std::endl;
	std::cout << "d: " << d << std::endl;
	std::cout << "d: " << d++ << std::endl;
	std::cout << "d: " << d << std::endl;
	std::cout << std::endl;

	std::cout << PINK << "* Decrementing numbers *" << RESET << std::endl;
	std::cout << "d: " << --d << std::endl;
	std::cout << "d: " << d << std::endl;
	std::cout << "d: " << d-- << std::endl;
	std::cout << "d: " << d << std::endl;
	std::cout << std::endl;

	std::cout << PINK << "* Getting Min/Max *" << RESET << std::endl;
	std::cout << "min(d, f): " << Fixed::min(d, f) << std::endl;
	std::cout << "min(d, f): " << Fixed::min(d, f) << std::endl;
	std::cout << "max(d, f): " << Fixed::max(d, f) << std::endl;
	std::cout << "max(d, f): " << Fixed::max(d, f) << std::endl;

}