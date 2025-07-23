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
PresidentialPardonForm::PresidentialPardonForm(void) {};

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) 
{ 
    *this = other;
};

PresidentialPardonForm::~PresidentialPardonForm(void) {};

/* *************************** Assignment Operator ************************** */
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    return *this;
};