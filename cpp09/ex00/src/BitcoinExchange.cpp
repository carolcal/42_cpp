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
BitcoinExchange::BitcoinExchange(void) : _database(NULL), _query(NULL) {};

BitcoinExchange::BitcoinExchange(std::string database, std::string query)
{
	open_file(_query, query);
	open_file(_database, database);
};

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) { *this = other; };

BitcoinExchange::~BitcoinExchange(void) {};

/* *************************** Assignment Operator ************************** */
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		*this = other;
	return *this;
}

/* ***************************** Member Functions *************************** */
void BitcoinExchange::printConversion(void)
{
	std::string content;
	std::vector<int> date;
	std::string s_date;
	float value;
	float price;
	int	line_index = 0;

	while(getline(_query, content))
	{
		if (line_index == 0 && content != "date | value")
			throw std::runtime_error("Invalid input file.");
		if (line_index > 0)
		{
			try
			{
				s_date = getContent(content, date, value, "query");
				validateDate(date, s_date);
				validateValue(value);
				getPrice(date, value, price);
				printContent(date, value, price);
			}
			catch(const std::exception& e)
			{
				std::cerr << "Error: " << e.what() << std::endl;
			}
			
		}
		date.clear();
		value = 0;
		price = 0;
		line_index++;
	}
}

void BitcoinExchange::printContent(std::vector<int> &date, float &value, float &price)
{
	int y = date[0];
	int m = date[1];
	int d = date[2];

	std::cout << y << "-" << m << "-" << d << " => " << value << " = " << price << std::endl;
}

std::string BitcoinExchange::getContent(std::string content, std::vector<int> &date, float &value, std::string type)
{
	std::string datePart;
	std::string valuePart;
	std::istringstream iss(content);

	if (type == "database")
		std::getline(iss, datePart, ',');
	else
		std::getline(iss, datePart, '|');
	std::getline(iss, valuePart);

	datePart = trim(datePart);
	valuePart = trim(valuePart);

	std::istringstream dateStream(datePart);
	std::string token;
	while (std::getline(dateStream, token, '-'))
		date.push_back(castInt(token, datePart));

	if (type == "database")
		value = castFloat(valuePart, "exchange rate");
	else
		value = castFloat(valuePart, "value");
	
	return(datePart);
}


void BitcoinExchange::getPrice(std::vector<int> &date, float &value, float &price)
{
	std::string dt_content;
	std::vector<int> dt_date;
	float dt_value;
	int	line_index = 0;

	_database.clear();
	_database.seekg(0); 
	while(getline(_database, dt_content))
	{
		if (line_index == 0 && dt_content != "date,exchange_rate")
			throw std::runtime_error("Invalid 'data.csv' file.");
		if (line_index > 0)
		{
			getContent(dt_content, dt_date, dt_value, "database");
			if (dt_date[0] < date[0])
				price = value * dt_value;
			else if (dt_date[0] == date[0] && dt_date[1] < date[1])
				price = value * dt_value;
			else if (dt_date[0] == date[0] && dt_date[1] == date[1]  && dt_date[2] <= date[2])
				price = value * dt_value;
			else
				break ;
			dt_date.clear();
			dt_value = 0;
		}
		line_index++;
	};
}

/* **************************** Validate Functions ************************** */
void BitcoinExchange::validateDate(std::vector<int> date, std::string s_date)
{
	if (date.size() != 3)
		throw std::range_error("Bad Input: Invalid date => " + s_date);

	int y = date[0];
	int m = date[1];
	int d = date[2];

	if (y < 2009 || y > 2022)
		throw std::range_error("Year is out of database range => " + s_date);
	if (m < 1 || m > 12)
		throw std::range_error("Bad Input: Invalid date => " + s_date);
	if (mounthType(m) == 1 && ( d < 1 || d > 31))
		throw std::range_error("Bad Input: Invalid date=> " + s_date);
	if (mounthType(m) == 0 && (d < 1 || d > 30))
		throw std::range_error("Bad Input: Invalid date => " + s_date);
	if (mounthType(m) == 2 && isLeap(y) && (d < 1 || d > 29))
		throw std::range_error("Bad Input: Invalid date => " + s_date);
	if (mounthType(m) == 2 && !isLeap(y) && (d < 1 || d > 28))
		throw std::range_error("Bad Input: Invalid date => " + s_date);
	if (y == 2009 && m == 1 && d == 1)
		throw std::range_error("Bad Input: Date out of range => " + s_date);
	if (y == 2022 && m == 3 && d > 29)
		throw std::range_error("Bad Input: Date out of range => " + s_date);
	if (y == 2022 && m > 3)
		throw std::range_error("Bad Input: Date out of range => " + s_date);
};

void BitcoinExchange::validateValue(float value)
{
	if (value < 0)
		throw std::range_error("Not a positive number.");
	if (value > 1000)
		throw std::range_error("Too large a number.");
};

/* ***************************** Helper Functions *************************** */
void BitcoinExchange::open_file(std::ifstream &file, std::string filename)
{
	file.open(filename.c_str());
	if (!file)
		throw std::runtime_error("Error: Opening file " + filename);
	if (file.peek() == EOF)
		throw std::runtime_error("Error: File '" + filename + "' is empty.");
};

bool BitcoinExchange::isLeap(int y)
{
	return ( y % 400 == 0 || ( y % 100 != 0 && y % 4 == 0 ));
};

int BitcoinExchange::mounthType(int m)
{
	if (m == 2)
		return 2;
	if ((m < 8 && m % 2 == 1) || (m > 7 && m % 2 == 0))
		return 1;
	return 0;
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
}
