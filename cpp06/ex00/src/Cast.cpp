/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cast.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 06:08:45 by marvin            #+#    #+#             */
/*   Updated: 2025/07/25 06:08:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cast.hpp"

void castChar(const std::string s)
{
	std::cout << "char: ";
	if (isInf(s) || isInff(s) || isNan(s) || isNanf(s))
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	if (!isChar(s))
	{
		int	i = atoi(s.c_str());
		char c = static_cast<char>(i);
		if (isprint(c))
			std::cout << c << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	}
	else
		std::cout << s << std::endl;
};

void castInt(const std::string s)
{
	int i;

	std::cout << "int: ";
	if (isInf(s))
	{
		std::cout << s << std::endl;
		return ;
	}
	if (isInff(s))
	{
		std:: string inf = s;
		std::cout << inf.erase(inf.size() - 1) << std::endl;
		return ;
	}
	if (isNan(s) || isNanf(s))
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	if (isChar(s))
		i = (int)s[0];
	else
		i = atoi(s.c_str());
	std::cout << i << std::endl;
};

void castFloat(const std::string s)
{
	float f;

	std::cout << "float: ";
	if (isInf(s))
	{
		std::cout << s << "f" << std::endl;
		return ;
	}
	if (isInf(s) || isInff(s))
	{
		std::cout << s << std::endl;
		return ;
	}
	if (isNan(s) || isNanf(s))
	{
		std::cout << "nanf" << std::endl;
		return ;
	}
	if (isChar(s))
		f = (float)s[0];
	else
		f = atof(s.c_str());
	std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
};

void castDouble(const std::string s)
{
	double d;

	std::cout << "double: ";
	if (isInf(s))
	{
		std::cout << s << std::endl;
		return ;
	}
	if (isInff(s))
	{
		std:: string inf = s;
		std::cout << inf.erase(inf.size() - 1) << std::endl;
		return ;
	}
	if (isNan(s) || isNanf(s))
	{
		std::cout << "nan" << std::endl;
		return ;
	}
	if (isChar(s))
		d = (double)s[0];
	else
		d = atof(s.c_str());
	std::cout << std::fixed << std::setprecision(1) << d << std::endl;
};
