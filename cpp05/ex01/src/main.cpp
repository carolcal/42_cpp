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
	std::cout << PINK << "* Creating Bureaucrat *" << RESET << std::endl;
	Bureaucrat* john = new Bureaucrat("John", 50);
	std::cout << *john << std::endl;

    std::cout << PINK << "* Creating Forms *" << RESET << std::endl;
	Form* f0 = new Form();
    std::cout << *f0 << std::endl;
	Form* f1 = new Form("Lunch", 30, 15);
    std::cout << *f1 << std::endl;
    Form* f2 = new Form("Vacation", 80, 40);
    std::cout << *f2 << std::endl;

    std::cout << PINK << "* Signing Forms *" << RESET << std::endl;
    john->signForm(*f0);
    john->signForm(*f1);
    john->signForm(*f2);

    std::cout << PINK << "* Creating Forms *" << RESET << std::endl;
    std::cout << *f0 << std::endl;
    std::cout << *f1 << std::endl;
    std::cout << *f2 << std::endl;

	delete john;
	delete f0;
	delete f1;
    delete f2;
}