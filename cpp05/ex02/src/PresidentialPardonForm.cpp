/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentalPardonForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 17:27:36 by marvin            #+#    #+#             */
/*   Updated: 2025/07/23 17:27:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/* *********************** Constructors and Destructor ********************** */
PresidentialPardonForm::PresidentialPardonForm(void) : 
    AForm("Presidential", "Anonimus", 25, 5)
{};

PresidentialPardonForm::PresidentialPardonForm(const std::string target) :
    AForm("Presidential", target, 25, 5)
{};

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) 
{ 
    *this = other;
};

PresidentialPardonForm::~PresidentialPardonForm(void) {};

/* *************************** Assignment Operator ************************** */
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    (void) other;
    return *this;
};

/* ***************************** Member Functions *************************** */
void    PresidentialPardonForm::beExecuted(void) const
{
    std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}