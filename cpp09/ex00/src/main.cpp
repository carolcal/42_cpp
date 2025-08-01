/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 12:10:12 by marvin            #+#    #+#             */
/*   Updated: 2025/07/31 12:10:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"



void open_file(std::ifstream &file, std::string filename)
{
	file.open(filename.c_str());
	if (!file)
		throw std::runtime_error("Error: Opening file.");
	if (file.peek())
		throw std::runtime_error("Error: File is empty.");
};

void read_file(std::ifstream &file)
{
	BitcoinExchange btc("data.csv")
	std::string content;

	while(getline(file, content))
	{
		btc.consultarValores(content);
		btc.printContent();
	}
};

int main(int ac, char *av[])
{
	std::string filename;
	std::ifstream file;

	if (ac != 2)
		throw std::runtime_error("Usage: ./btc <file.txt>");
	filename = av[1];
	open_file(file, filename);
	read_file(file);
};
