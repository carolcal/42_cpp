/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TypeIdentifier.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 05:31:45 by marvin            #+#    #+#             */
/*   Updated: 2025/07/25 05:31:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TypeIdentifier.hpp"

std::string skipSpaces(const std::string& s) {
    size_t i = 0;
    while (i < s.size() && isspace(s[i]))
        i++;
    return s.substr(i);
}

bool    isChar(const std::string s)
{
	return (s.length() == 1 && isprint(s[0]) && !isdigit(s[0]));
};

bool    isInt(const std::string s)
{
	int					i;
	std::istringstream	iss(s);

	return (iss >> i) && iss.eof();
};

bool    isFloat(const std::string s)
{
	std::string s_trim = skipSpaces(s);

	if (s_trim == "-inff" || s_trim == "+inff" || s_trim == "inff" || s_trim == "nanf")
		return true;
	if (s_trim.size() < 2 || s_trim[s_trim.size() - 1] != 'f')
		return false;

	std::string n = s_trim.substr(0, s_trim.size() - 1);

	float				f;
	std::istringstream	iss(n);

	return (iss >> f) && iss.eof();
};

bool    isDouble(const std::string s)
{
	if (s == "-inf" || s == "+inf" || s == "inf" || s == "nan")
		return true;

	double				d;
	std::istringstream	iss(s);

	return (iss >> d) && iss.eof();
};
