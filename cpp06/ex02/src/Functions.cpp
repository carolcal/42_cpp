/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 16:57:41 by cayamash          #+#    #+#             */
/*   Updated: 2025/07/25 17:59:14 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Functions.hpp"

Base	*generate(void)
{
	std::srand(std::time(0)); // seed with current time (only once!)
	int random = (std::rand() % 3);

	switch (random)
	{
	case 0:
		std::cout << "Instantiating class A." << std::endl;
		return new A;
		break;
	case 1:
		std::cout << "Instantiating class B." << std::endl;
		return new B;
		break;
	case 2:
		std::cout << "Instantiating class C." << std::endl;
		return new C;
		break;
	
	default:
		std::cout << "Error instantiating." << std::endl;
		return (NULL);
		break;
	}
}

void	identify(Base* p)
{
	std::cout << "Pointer: ";
	if (dynamic_cast<A *>(p))
		std::cout << "Class type A." << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "Class type B." << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "Class type C." << std::endl;
	else
		std::cout << "Class type None." << std::endl;
}

void	identify(Base &p)
{
	std::cout << "Reference: ";
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "Class type A." << std::endl;
		return ;
	}
	catch (std::exception &) {};
	
	try
	{
		(void)dynamic_cast<B &>(p);
		std::cout << "Class type B." << std::endl;
		return ;
	}
	catch (std::exception &) {};

	try
	{
		(void)dynamic_cast<C &>(p);
		std::cout << "Class type C." << std::endl;
		return ;
	}
	catch (std::exception &) 
	{
		std::cout << "Class type None." << std::endl;
	};
}