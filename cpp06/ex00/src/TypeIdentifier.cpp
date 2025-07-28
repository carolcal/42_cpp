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
	if (isInff(s) || isNanf(s))
		return true;
	if (s.size() < 2 || s[s.size() - 1] != 'f')
		return false;

	std::string n = s.substr(0, s.size() - 1);

	float				f;
	std::istringstream	iss(n);

	return (iss >> f) && iss.eof();
};

bool    isDouble(const std::string s)
{
	if (isInf(s) || isNan(s))
		return true;

	double				d;
	std::istringstream	iss(s);

	return (iss >> d) && iss.eof();
};

bool	isInf(const std::string s)
{
	return (s == "-inf" || s == "+inf" || s == "inf");
}

bool	isInff(const std::string s)
{
	return (s == "-inff" || s == "+inff" || s == "inff");
}

bool	isNan(const std::string s)
{
	return (s == "nan");
}

bool	isNanf(const std::string s)
{
	return (s == "nanf");
}
