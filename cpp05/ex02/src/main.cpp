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
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	std::cout << PINK << "* Creating Bureaucrat *" << RESET << std::endl;
	Bureaucrat* john = new Bureaucrat("John", 150);
	std::cout << *john << std::endl;

	std::cout << PINK << "* Creating Forms *" << RESET << std::endl;
	AForm* f0 = new ShrubberyCreationForm("home");
	std::cout << *f0 << std::endl;
	AForm* f1 = new RobotomyRequestForm("human");
	std::cout << *f1 << std::endl;
	AForm* f2 = new PresidentialPardonForm("illegal immigrant");
	std::cout << *f2 << std::endl;

	std::cout << PINK << "* Trying to sign and excute forms *" << RESET << std::endl;
	john->signForm(*f0);
	john->executeForm(*f0);

	john->incrementGrade(10);
	john->signForm(*f0);
	john->executeForm(*f0);

	john->incrementGrade(20);
	john->executeForm(*f0);
	john->signForm(*f1);

	john->incrementGrade(60);
	john->signForm(*f1);
	john->executeForm(*f1);

	john->incrementGrade(30);
	john->executeForm(*f1);
	john->signForm(*f2);

	john->incrementGrade(20);
	john->signForm(*f2);
	john->executeForm(*f2);

	john->incrementGrade(9);
	john->executeForm(*f2);

	std::cout << PINK << "* Verifying Forms *" << RESET << std::endl;
	std::cout << *f0 << std::endl;
	std::cout << *f1 << std::endl;
	std::cout << *f2 << std::endl;

	delete john;
	delete f0;
	delete f1;
	delete f2;
}

// int main(void)
// {
// 	ShrubberyCreationForm shrubbery("Monkey");
// 	RobotomyRequestForm robotomy("Barney");
// 	PresidentialPardonForm president("Alien");

// 	shrubbery.beExecuted();
// 	robotomy.beExecuted();
// 	president.beExecuted();

// }