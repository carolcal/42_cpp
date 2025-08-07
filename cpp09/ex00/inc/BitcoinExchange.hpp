/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 11:55:09 by marvin            #+#    #+#             */
/*   Updated: 2025/07/31 11:55:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <cstdlib>
# include <string>
# include <map>

struct Date
{
	int year;
	int month;
	int day;

	bool operator<(const Date &other) const
	{
		if (year != other.year)
			return (year < other.year);
		if (month != other.month)
			return (month < other.month);
		return day < other.day;
	}
	bool operator>(const Date &other) const
	{
		if (year != other.year)
			return (year > other.year);
		if (month != other.month)
			return (month > other.month);
		return day > other.day;
	}

	void clear(void)
	{
		year = 0;
		month = 0;
		day = 0;
	}
};

class BitcoinExchange
{
	private:
		std::ifstream			_databaseFile;
		std::map<Date, float>	_database;

		/* ************ Constructors ************ */
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange &other);

		/* ************* Operators ************** */
		BitcoinExchange& operator=(const BitcoinExchange &other);

		/* ********** Member Functions ********** */
		void		loadDatabase(void);
		void		getContent(std::string content, Date &date, float &value, std::string type);
		void		getDate(Date &date, std::string datePart);
		void		getValue(float &value, std::string valuePart, std::string type);
		void		getPrice(Date &date, float &value, float &price);
		void		validateDate(Date &date);
		void		validateValue(float value);
		

	public:
		/* ***** Constructors and Destructor **** */
		BitcoinExchange(std::string database);
		~BitcoinExchange(void);

		/* ********** Member Functions ********* */
		void		printConversion(std::string input);
};

/* ********** Helper Functions ********** */
void		open_file(std::ifstream &file, std::string filename);
void		printContent(Date &date, float &value, float &price);
int			getMonthDays(int m, int y);
bool		isLeap(int y);
int			castInt(std::string s, std::string type);
float		castFloat(std::string s, std::string type);
std::string	trim(const std::string &str);
std::string	dateToString(Date &date);

#endif