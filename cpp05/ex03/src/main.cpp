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
#include "Intern.hpp"

int main(void)
{
	std::cout << PINK << "* Creating Intern *" << RESET << std::endl;
	Intern someRandomIntern;

	std::cout << PINK << "* Creating Forms *" << RESET << std::endl;
	AForm* scf = someRandomIntern.makeForm("shrubbery request", "Tipo Ana");
	AForm* rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	AForm* ppf = someRandomIntern.makeForm("presidential request", "Sensored");

	std::cout << PINK << "* Verifying Forms *" << RESET << std::endl;
	std::cout << *scf << std::endl;
	std::cout << *rrf << std::endl;
	std::cout << *ppf << std::endl;

	std::cout << PINK << "* Creating Bureaucrat *" << RESET << std::endl;
	Bureaucrat someRandomBureaucrat("someRandomBureaucrat", 1);

	std::cout << PINK << "* Signing Forms *" << RESET << std::endl;
	someRandomBureaucrat.signForm(*scf);
	someRandomBureaucrat.signForm(*rrf);
	someRandomBureaucrat.signForm(*ppf);

	std::cout << PINK << "* Verifying Forms *" << RESET << std::endl;
	std::cout << *scf << std::endl;
	std::cout << *rrf << std::endl;
	std::cout << *ppf << std::endl;

	delete scf;
	delete rrf;
	delete ppf;
	return (0);
}

