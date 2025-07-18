/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 14:35:37 by cayamash          #+#    #+#             */
/*   Updated: 2025/07/15 11:24:55 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

bool	isValid(const std::string& field, const std::string& type)
{
	int	i = 0;
	while (field[i])
	{
		if (type == "alphabetic" && !isalpha(field[i]) && !isspace(field[i]))
			return (false);
		if (type == "numeric" && !isdigit(field[i]) && field[i] != '(' 
			&& field[i] != ')' && field[i] != '+' && !isspace(field[i]))
			return (false);
		i++;
	}
	return (true);
}

std::string	getValidField(const std::string& prompt, const std::string& type)
{
	std::string	field;
	
	while (true)
	{
		std::cout << prompt << ": ";
		std::getline(std::cin, field);
		if (std::cin.eof())
		{
			std::cout << "\nYou choose to give up! :(\n";
			std::exit(1);
		}
		if (field.empty())
			std::cout << "You didn't wrote anything... try again!\n";
		if (!isValid(field, type))
			std::cout << "Not a valid field, please enter " << type << " caracters... try again!\n";
		else
			break ;
	}
	return (field);
}

void    Contact::setFields()
{
	first_name = getValidField("First Name", "alphabetic");
	last_name = getValidField("Last Name", "alphabetic");
	nickname = getValidField("Nickname", "all");
	phone_number = getValidField("Phone Number", "numeric");
	darkest_secret = getValidField("Darkest Secret", "all");
}

std::string truncate(const std::string& text)
{
	if (text.length() > 10)
		return text.substr(0, 9) + ".";
	return text;
}

void	Contact::displayTableInfo(int i)
{
	std::cout << "|" << std::setw(10) << i
		<< "|" << std::setw(10) << truncate(first_name)
		<< "|" << std::setw(10) << truncate(last_name)
		<< "|" << std::setw(10) << truncate(nickname)
		<< "|" << std::endl;
}

void	Contact::displayDetailedInfo(int i)
{
	std::cout << "ID: " << i << "\n"
		<< "First Name: " << first_name << "\n"
		<< "Last Name: " << last_name << "\n"
		<< "Nickname: " << nickname << "\n"
		<< "Phone Number: " << phone_number << "\n"
		<< "Darkest Secret: " << darkest_secret
		<< std::endl;
}
