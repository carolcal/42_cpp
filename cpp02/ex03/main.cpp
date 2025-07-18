/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 17:18:02 by cayamash          #+#    #+#             */
/*   Updated: 2025/07/18 11:50:31 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"


int main( void )
{
	Point	a(2.5f, 4);
	Point	b(0, 1.25f);
	Point	c(3, 2);
	Point 	p_inside(1.5f, 2.0f);
	Point 	p_outside(3.5f, 4.0f);
	Point 	p_vertice = a;
	Point	p_edge(1.25f, 2.625f);

	std::cout << PINK << "* Triangle *" << RESET << std::endl;
	std::cout << "a: " << a.getX() << ", " << a.getY() << std::endl;
	std::cout << "b: " << b.getX() << ", " << b.getY() << std::endl;
	std::cout << "c: " << c.getX() << ", " << c.getY() << std::endl;
	
	std::cout << PINK << "* Testing point inside *" << RESET << std::endl;
	std::cout << "point: " << p_inside.getX() << ", " << p_inside.getY() << std::endl;
	std::cout << "is inside? " << (bsp(a, b, c, p_inside) == 1 ? "yes" : "no") << std::endl;

	std::cout << PINK << "* Testing point outside *" << RESET << std::endl;
	std::cout << "point: " << p_outside.getX() << ", " << p_outside.getY() << std::endl;
	std::cout << "is inside? " << (bsp(a, b, c, p_outside) == 1 ? "yes" : "no") << std::endl;

	std::cout << PINK << "* Testing point vertice *" << RESET << std::endl;
	std::cout << "point: " << p_vertice.getX() << ", " << p_vertice.getY() << std::endl;
	std::cout << "is inside? " << (bsp(a, b, c, p_vertice) == 1 ? "yes" : "no") << std::endl;

	std::cout << PINK << "* Testing point edge *" << RESET << std::endl;
	std::cout << "point: " << p_edge.getX() << ", " << p_edge.getY() << std::endl;
	std::cout << "is inside? " << (bsp(a, b, c, p_edge) == 1 ? "yes" : "no") << std::endl;
	
	
}