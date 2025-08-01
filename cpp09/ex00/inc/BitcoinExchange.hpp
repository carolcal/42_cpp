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
		void	printContent(std::vector<int> &date, int &value, int &price);

		void	getContent(std::string content, std::vector<int> &date, int &value);
		void	getPrice(std::vector<int> &date, int &value, int &price);

		void	validateDate(std::vector<int> date);
		void	validateValue(int value);

		void	open_file(std::ifstream &file, std::string filename);
		bool	isLeap(int y);
		int		mounthType(int m);
		int		castInt(std::string s);

	public:
		/* ***** Constructors and Destructor **** */
		BitcoinExchange(std::string database, std::string query);
		~BitcoinExchange(void);

		/* ********** Member Functions ********* */
		void	printConversion(void);
};

#endif