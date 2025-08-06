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
BitcoinExchange::BitcoinExchange(void) : _databaseFile(), _database() {};

BitcoinExchange::BitcoinExchange(std::string database)
{
	open_file(_databaseFile, database);
	loadDatabase(_databaseFile, _database);
};

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) { *this = other; };

BitcoinExchange::~BitcoinExchange(void) {};

/* *************************** Assignment Operator ************************** */
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		*this = other;
	return *this;
};

/* ***************************** Member Functions *************************** */
void BitcoinExchange::open_file(std::ifstream &file, std::string filename)
{
	file.open(filename.c_str());
	if (!file)
		throw std::runtime_error("Error: Opening file " + filename);
	if (file.peek() == EOF)
		throw std::runtime_error("Error: File '" + filename + "' is empty.");
};

void BitcoinExchange::loadDatabase(std::ifstream &file, std::map<Date, float> &container)
{
	std::string	content;
	Date		date;
	float		value;
	int			line_index = 0;

	while(getline(file, content))
	{
		if (line_index == 0 && content != "date,exchange_rate")
			throw std::runtime_error("Invalid 'data.csv' file.");
		if (line_index > 0)
		{
			getContent(content, date, value, "database");
			container[date] = value;
			date.clear();
		}
		line_index++;
	}
};

/* ***************************** Print Functions **************************** */

void BitcoinExchange::printConversion(std::string input)
{
	std::ifstream	_inputFile;
	std::string		content;
	Date			date;
	float			value;
	float			price;
	int				line_index = 0;

	open_file(_inputFile, input);
	while(getline(_inputFile, content))
	{
		if (line_index == 0 && content != "date | value")
			throw std::runtime_error("Invalid input file.");
		if (line_index > 0)
		{
			try
			{
				getContent(content, date, value, "input");
				getPrice(date, value, price);
				printContent(date, value, price);
			}
			catch(const std::exception& e)
			{
				std::cerr << "Error: " << e.what() << std::endl;
			}
		}
		date.clear();
		line_index++;
	}
};

void BitcoinExchange::printContent(Date &date, float &value, float &price)
{
	std::cout << dateToString(date) << " => " << value << " = " << price << std::endl;
};

/* ****************************** Get Functions ***************************** */

void BitcoinExchange::getContent(std::string content, Date &date, float &value, std::string type)
{
	std::string			datePart;
	std::string			valuePart;
	std::istringstream	iss(content);

	if (type == "database")
		std::getline(iss, datePart, ',');
	else
		std::getline(iss, datePart, '|');
	std::getline(iss, valuePart);

	datePart = trim(datePart);
	valuePart = trim(valuePart);

	getDate(date, datePart);
	getValue(value, valuePart, type);
};

void BitcoinExchange::getDate(Date &date, std::string datePart)
{
	std::string			token;
	std::istringstream	dateStream(datePart);

	if (!std::getline(dateStream, token, '-'))
		throw std::runtime_error("Bad Input: Invalid year => " + datePart);
	date.year = castInt(token, datePart);

	if (!std::getline(dateStream, token, '-'))
		throw std::runtime_error("Bad Input: Invalid month => " + datePart);
	date.month = castInt(token, datePart);
	
	if (!std::getline(dateStream, token))
		throw std::runtime_error("Bad Input: Invalid day => " + datePart);
	date.day = castInt(token, datePart);

	validateDate(date);
};

void BitcoinExchange::getValue(float &value, std::string valuePart, std::string type)
{
	if (type == "database")
		value = castFloat(valuePart, "exchange rate");
	else
	{
		value = castFloat(valuePart, "value");
		validateValue(value);
	}
};

void BitcoinExchange::getPrice(Date &date, float &value, float &price)
{
	std::map<Date, float>::iterator it = _database.upper_bound(date);
	if (it == _database.begin())
		throw std::runtime_error("No record found for date => " + dateToString(date));
	--it;
	price = it->second * value;
};

int BitcoinExchange::getMonthDays(int m, int y)
{
	if (m == 2)
		return isLeap(y) ? 29 : 28;
	if ((m < 8 && m % 2 == 1) || (m > 7 && m % 2 == 0))
		return 31;
	return 30;
};

/* **************************** Validate Functions ************************** */
void BitcoinExchange::validateDate(Date &date)
{
	int max_day = getMonthDays(date.month, date.year);
	const Date minDate = {2009, 1, 2};
	const Date maxDate = {2022, 3, 29};

	if (date.year < 2009 || date.year > 2022)
		throw std::range_error("Year is out of database range => " + dateToString(date));
	if (date.month < 1 || date.month > 12)
		throw std::range_error("Bad Input: Invalid month => " + dateToString(date));
	if (date.day < 1 || date.day > max_day)
		throw std::range_error("Bad Input: Invalid day => " + dateToString(date));
	if (date < minDate || date > maxDate)
		throw std::range_error("Bad Input: Date out of range => " + dateToString(date));
}
void BitcoinExchange::validateValue(float value)
{
	if (value < 0)
		throw std::range_error("Not a positive number.");
	if (value > 1000)
		throw std::range_error("Too large a number.");
};

/* ***************************** Helper Functions *************************** */

bool BitcoinExchange::isLeap(int y)
{
	return ( y % 400 == 0 || ( y % 100 != 0 && y % 4 == 0 ));
};

int BitcoinExchange::castInt(std::string s, std::string datePart)
{
	int i;
	s = trim(s);
	std::istringstream	iss(s);

	if ((iss >> i) && iss.eof())
		i = atoi(s.c_str());
	else
		throw std::runtime_error("Bad Input: Invalid date => " + datePart);
	return i;
};

float BitcoinExchange::castFloat(std::string s, std::string type)
{
	int len = 0;
	float f;
	s = trim(s);

	std::istringstream	iss(s);

	while (s[len] && s[len] == '.')
		len++;
	if (len > 5)
		throw std::range_error("Too large a number.");
	if ((iss >> f) && iss.eof())
		f = atof(s.c_str());
	else
		throw std::runtime_error("Bad Input: Invalid " + type + ".");
	return f;
};

std::string BitcoinExchange::trim(const std::string &str)
{
	size_t start = 0;
	while (start < str.size() && isspace(str[start]))
		start++;
	size_t end = str.size();
	while (end > start && isspace(str[end - 1]))
		end--;
	return str.substr(start, end - start);
};

std::string BitcoinExchange::dateToString(Date &date) const
{
	std::ostringstream oss;
	oss << date.year << "-";
	if (date.month < 10) oss << "0";
	oss << date.month << "-";
	if (date.day < 10) oss << "0";
	oss << date.day;
	return oss.str();
};