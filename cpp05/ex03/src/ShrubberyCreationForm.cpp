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
ShrubberyCreationForm::ShrubberyCreationForm(void) : 
	AForm("Shrubbery", "Anonimus", 145, 137) 
{};

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target):
	AForm("Shrubbery", target, 145, 137)
{};

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) 
{ 
	*this = other;
};

ShrubberyCreationForm::~ShrubberyCreationForm(void) {};

/* *************************** Assignment Operator ************************** */
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	(void)other;
	return *this;
};

/* ***************************** Member Functions *************************** */
void    ShrubberyCreationForm::beExecuted(void) const
{
	std::string fileName = (getTarget() + "_shrubbery");
	std::ofstream file(fileName.c_str());
	if (file.is_open())
	{
		file << "            ,@@@@@@@,\n";
		file << "    ,,,.   ,@@@@@@/@@,  .oo8888o.\n";
		file << ",&%&&%&&%,@@@@@/@@@@@@,8888888/8o\n";
		file << ",%&&%&&%&&%,@@\\@@@/@@@88\\8888/88'\n";
		file << "%&&%&%&/%&&%@@\\@/ /@@@88888/88888'\n";
		file << "%&&%/ %&&%&&@@@\\/@@' `8888 `/88'\n";
		file << "`&%\\` /%&'    |.|        \\'|8'\n";
		file << "    |o|        | |         | |\n";
		file << "    |.|        | |         | |\n";
		file << " \\/ .\\//_/__/ ,\\_//__\\/. \\_//__/_\n";
		file.close();
	}
};

