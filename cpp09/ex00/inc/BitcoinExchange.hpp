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

#include <iostream>
#include <string>
#include <vector>

class BitcoinExchange
{
    private:
        std::ifstream _database;
        std::ifstream _query;

        /* ************ Constructors ************ */
        BitcounExchange(void);
        BitcoinExchange(const BitcoinExchange &other);

        /* ********** Member Functions ********* */
        void getContent(std::string, std::vector<int> &date, int &value)

        void validateDate(std::vector<int> date);
        void validateValue(int value);
    public:
        /* ***** Constructors and Destructor **** */
        BitcounExchange(std::string database, std::string query);
        ~BitcoinExchange(void);

        /* ************* Operators ************* */
        BitcointExchange& operator=(const BitcointExchange &other);

        /* ********** Member Functions ********* */
        void printContent(void);
}

#endif