/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 14:31:57 by cayamash          #+#    #+#             */
/*   Updated: 2025/07/15 11:22:47 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

int main()
{
    Phonebook	myPhonebook;
    std::string	command;

	while (42)
	{
		std::cout << "Type a command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, command);
		if (std::cin.eof())
		{
			std::cout << "\nAll right... exiting...\n";
			std::exit(1);
		}
		if (command == "ADD")
			myPhonebook.add();
		else if (command == "SEARCH")
			myPhonebook.search();
		else if (command == "EXIT")
		{
			std::cout << "Deleting everything and exiting... Bye bye" << std::endl;
			break ;
		}
		else
			std::cout << "Invalid command! Please try again!" << std::endl;
	}
	return (0);
}
