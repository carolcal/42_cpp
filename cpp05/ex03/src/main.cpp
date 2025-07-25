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
	std::cout << PINK << "* Creating Inter *" << RESET << std::endl;
	Intern someRandomIntern();

	std::cout << PINK << "* Creating Forms *" << RESET << std::endl;
	AForm* scf = someRandomIntern.makeForm("Shrubbery request", "Tipo Ana");
	AForm* rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	AForm* ppf = someRandomIntern.makeForm("presidential request", "sendored");



	std::cout << PINK << "* Verifying Forms *" << RESET << std::endl;
	std::cout << *f0 << std::endl;
	std::cout << *f1 << std::endl;
	std::cout << *f2 << std::endl;

}

