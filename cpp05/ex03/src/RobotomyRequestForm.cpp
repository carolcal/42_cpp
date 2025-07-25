/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 17:27:55 by marvin            #+#    #+#             */
/*   Updated: 2025/07/23 17:27:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/* *********************** Constructors and Destructor ********************** */
RobotomyRequestForm::RobotomyRequestForm(void) : 
	AForm("Robotomy", "Anonimus", 72, 45)
{};

RobotomyRequestForm::RobotomyRequestForm(const std::string target) :
	AForm("Robotomy", target, 72, 45)
{};

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) 
{ 
	*this = other;
};

RobotomyRequestForm::~RobotomyRequestForm(void) {};

/* *************************** Assignment Operator ************************** */
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	(void)other;
	return *this;
};

/* ***************************** Member Functions *************************** */
void    RobotomyRequestForm::beExecuted(void) const
{
	std::cout << "Bep beep ..Bzzzrr... Brzzz Zzzzrrbip boptbuppzzz... " << std::endl;
	std::time_t now = std::time(NULL);
	if (now % 2)
		std::cout << getTarget() << " has been robotomized successfully!" << std::endl;
	else
		std::cout << "Failed to robotomize " << getTarget() << "!" << std::endl;
}