/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 20:46:14 by marvin            #+#    #+#             */
/*   Updated: 2025/07/31 20:46:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/* *********************** Constructors and Destructor ********************** */
BitcoinExchange::BitcoinExchange(void) : database(NULL), query(NULL) {};

BitcoinExchange::BitcoinExchange(std::string database, std::string query) : 
{
	open_file(_database, database);
	open_file(_query, query);
};

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {this = &other};

BitcoiExchange::~BitcoinExchange(void) {};

/* *************************** Assignment Operator ************************** */
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != other)
		this = &other;
	return *this;
}

/* ***************************** Member Functions *************************** */
void printConversion(void)
{
	std::string content;
	std::vector<std::int> date;
	int value;
	int price

	while(getline(_query, content))
	{
		getContent(content, date, value);
		validateDate(date);
		validateValue(value);
		getPrice(price);
		printContent(date, value, price);

		date.clear();
		value.clear();
	}
}

void getContent(std::string, std::vector<int> &date, int &value)
{
	std::string datePart;
	std::string valuePart;
	std::istringstream iss(line);

	std::getline(iss, datePart, '|');
	std::getline(iss, valuePart);

	// Conver tValue
	while (!valuePart.empty() && valuePart[0] == ' ')
		valuePart.erase(0, 1);
	value = castInt(valuePart);

	// Convert Date
	std::istringstream dateStream(datePart);
	std::string token;
	while (std::getline(dateStream, token, '-')) 
		date.push_back(castInt(token));
}

/* **************************** Validate Functions ************************** */
void validateDate(std::vector<int> date)
{
	if (date.size != 3)
		throw std::out_of_range("Bad Input: Invalid date.");

	int y = date[0];
	int m = date[1];
	int d = date[2];

	if (y < 2009 || y > 2022)
		throw std::out_of_range("Year is out of database range.");
	if (m < 1 || m > 12)
		throw std::out_of_range("Bad Input: Invalid date.");
	if (mounthType(m) == 1 && ( d < 1 || d > 31))
		throw std::out_of_range("Bad Input: Invalid date.");
	if (mounthType(m) == 0 && (d < 1 || d > 30))
		throw std::out_of_range("Bad Input: Invalid date.");
	if (mounthType(m) == 2 && isLeap(y) && (d < 1 || d > 29))
		throw std::out_of_range("Bad Input: Invalid date.");
	if (mounthType(m) == 2 && !isLeap(y) && (d < 1 || d > 28))
		throw std::out_of_range("Bad Input: Invalid date.");
};

void validateValue(int value)
{
	if (value < 0)
		throw std::out_of_range("Not a positive number.");
	if (value > 1000)
		throw std::out_of_range("Too large number.");
};

/* ***************************** Helper Functions *************************** */
void open_file(std::ifstream &file, std::string filename)
{
	file.open(filename.c_str());
	if (!file)
		throw std::runtime_error("Error: Opening file " + filename);
	if (file.peek())
		throw std::runtime_error("Error: File " + filename + " is empty.");
};

bool isLeap(int y)
{
	return ( y % 400 == 0 || ( y % 100 != 0 && y % 4 == 0 ));
};

int mounthType(int m)
{
	if (m == 2)
		return 2;
	if ((m < 8 && m % 2 == 1) || (m > 7 && m % 2 == 0))
		return 1;
	return 0;
};

int castInt(std::string s)
{
	int i;
	std::istringstream	iss(s);

	if ((iss >> i) && iss.eof())
		i = atoi(s.c_str());
	else
		throw std::out_of_range("Bad Input: Invalid date.");
	return i;
};
