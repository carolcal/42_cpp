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
RobotomyRequestForm::RobotomyRequestForm(void) {};

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) 
{ 
    *this = other;
};

RobotomyRequestForm::~RobotomyRequestForm(void) {};

/* *************************** Assignment Operator ************************** */
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    return *this;
};