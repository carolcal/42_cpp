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
# include <vector>

class BitcoinExchange
{
	private:
		std::ifstream _database;
		std::ifstream _query;

		/* ************ Constructors ************ */
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange &other);

		/* ************* Operators ************* */
		BitcoinExchange& operator=(const BitcoinExchange &other);

		/* ********** Member Functions ********* */
		void	printContent(std::vector<int> &date, float &value, float &price);

		std::string	getContent(std::string content, std::vector<int> &date, float &value, std::string type);
		void	getPrice(std::vector<int> &date, float &value, float &price);

		void	validateDate(std::vector<int> date, std::string s_date);
		void	validateValue(float value);

		void	open_file(std::ifstream &file, std::string filename);
		bool	isLeap(int y);
		int		mounthType(int m);
		int		castInt(std::string s, std::string type);
		float	castFloat(std::string s, std::string type);
		std::string trim(const std::string &str);

	public:
		/* ***** Constructors and Destructor **** */
		BitcoinExchange(std::string database, std::string query);
		~BitcoinExchange(void);

		/* ********** Member Functions ********* */
		void	printConversion(void);
};

#endif