/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 17:32:25 by marvin            #+#    #+#             */
/*   Updated: 2025/07/23 17:32:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/* *********************** Constructors and Destructor ********************** */
ShrubberyCreationForm::ShrubberyCreationForm(void) {};

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) 
{ 
    *this = other;
};

ShrubberyCreationForm::~ShrubberyCreationForm(void) {};

/* *************************** Assignment Operator ************************** */
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    return *this;
};