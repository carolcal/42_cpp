/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 11:58:53 by cayamash          #+#    #+#             */
/*   Updated: 2025/07/08 19:07:02 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Phonebook::Phonebook() : count(0), index(0) {}

void    Phonebook::add()
{
    Contact newContact;
    newContact.setFields();
    contacts[index] = newContact;
	if(count < 8)
		count++;
	index = (index + 1) % 8;
    std::cout << "Contact added to Phonebook List!" << std::endl;
}

void Phonebook::search()
{
    int         i = 0;

    if (count == 0)
    {
        std::cout << "Your phonebook is empty. Add a contact!" << std::endl;
        return ;
    }
    std::cout << "|" << std::setw(10) << "ID" 
        << "|" << std::setw(10) << "First Name"
        << "|" << std::setw(10) << "Last Name"
        << "|" << std::setw(10) << "Nickname"
        << "|" << std::endl;
    while (i < count)
    {
        contacts[i].displayTableInfo(i);
        i++;
    }
    searchId();
}

void	Phonebook::searchId()
{
	int			index;
    std::string input;
	
	std::cout << "Type contact id number to see detailed info: ";
    std::getline(std::cin, input);
	if (std::cin.eof())
	{
		std::cout << "\nAll right... exiting...\n";
		std::exit(1);
	}
	if (input.length() != 1 || !isdigit(input[0]))
	{
		std::cout << "Invalid Index!" << std::endl;
		return ;
	}
	index = input[0] - '0';
	if (index > 7 || index >= count)
	{
		std::cout << "No contact in this index!" << std::endl;
		return ;
	}
	contacts[index].displayDetailedInfo(index);
}