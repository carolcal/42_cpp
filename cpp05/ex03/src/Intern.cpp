/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 15:55:50 by cayamash          #+#    #+#             */
/*   Updated: 2025/07/24 19:49:18 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

/* *********************** Constructors and Destructor ********************** */
Intern::Intern(void) {};

Intern::Intern(const Intern &other) {};

Intern::~Intern(void) {};

/* *************************** Assignment Operator ************************** */
Intern& Intern::operator=(const Intern &other)
{
	(void)this;
	return *this;
};

/* ***************************** Member Functions *************************** */
AForm&    makeForm(std::string name, std::string target)
{
	int i = 0;

	std::string forms[] = {
		"shrubbery request",
		"robotomy request",
		"presidential request"
	};
	
	switch(i)
	{
		case 0:
		{
			AForm *newForm = new ShrubberyCreationForm(target);
			std::cout << "Intern creates shrubbery creation form." << std::endl;
			break ;
		}
		case 1:
		{
			AForm *newForm = new RobotomyRequestForm(target);
			std::cout << "Intern creates robotomy request form." << std::endl;
			break ;
		}
		case 2:
		{
			AForm *newForm = new PresidentialPardonForm(target);
			std::cout << "Intern creates presidential pardon form" << std::endl;
			break;
		}
		default:
			std::cout << "Error creating form";
	};
	
}