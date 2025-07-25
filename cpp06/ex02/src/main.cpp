/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 17:13:39 by cayamash          #+#    #+#             */
/*   Updated: 2025/07/25 18:05:03 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Functions.hpp"

int main(void)
{
	std::cout << PINK << "\n* Creating Class *" << RESET << std::endl;
	Base *randomClass = generate();

	std::cout << PINK << "\n* Getting type of pointer *" << RESET << std::endl;
	identify(randomClass);

	std::cout << PINK << "\n* Getting type of reference *" << RESET << std::endl;
	identify(*randomClass);

	std::cout << std::endl;
	delete randomClass;
	return (0);
}