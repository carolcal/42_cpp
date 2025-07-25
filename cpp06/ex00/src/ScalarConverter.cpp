/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 05:03:29 by marvin            #+#    #+#             */
/*   Updated: 2025/07/25 05:03:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/* *********************** Constructors and Destructor ********************** */
ScalarConverter::ScalarConverter(void) {};

ScalarConverter::ScalarConverter(const ScalarConverter &other) { *this = other; };

ScalarConverter::~ScalarConverter(void) {};

/* *************************** Assignment Operator ************************** */
ScalarConverter& ScalarConverter::operator=(const ScalarConverter &other)
{
    (void)other;
    return *this;
};

/* ***************************** Member Functions *************************** */
void    ScalarConverter::converter(std::string s)
{
    //bool isConvertable = true;

    if (isChar(s))
    {
        std::cout << "Input is type <char>." << std::endl;
    }
    else if (isInt(s))
    {
        std::cout << "Input is type <int>." << std::endl;
    }
    else if (isFloat(s))
    {
        std::cout << "Input is type <float>." << std::endl;
    }
    else if(isDouble(s))
    {
        std::cout << "Input is type <double>." << std::endl;
    }
    else
    {
        std::cout << "Input is not convertable." << std::endl;
     //   isConvertable = false; 
    }

    /* if (isConvertible)
    {
        castChar(s);
        castInt(s);
        castFloat(s);
        castDouble(s);
    } */
};