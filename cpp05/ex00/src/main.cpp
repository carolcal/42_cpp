/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:36:55 by marvin            #+#    #+#             */
/*   Updated: 2025/07/23 11:36:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	std::cout << PINK << "* Creating Bureaucrats *" << RESET << std::endl;
	Bureaucrat* noONe = new Bureaucrat();
	std::cout << *noONe << std::endl;
	Bureaucrat* john = new Bureaucrat("John", 20);
	std::cout << *john << std::endl;

	std::cout << PINK << "\n* Incrementing and decrementing Grades with valid values *" << RESET << std::endl;
	john->incrementGrade(15);
	john->decrementGrade(30);

	std::cout << PINK << "\n* Incrementing and decrementing Grades with invalid values *" << RESET << std::endl;
	john->incrementGrade(-5);
	john->decrementGrade(-8);
	john->incrementGrade(50);
	john->decrementGrade(120);

	delete noONe;
	delete john;
}