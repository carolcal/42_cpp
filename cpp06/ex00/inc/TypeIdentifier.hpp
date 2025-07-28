/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TypeIdentifier.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 05:31:35 by marvin            #+#    #+#             */
/*   Updated: 2025/07/25 05:31:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEIDENTIFIER_HPP
#define TYPEIDENTIFIER_HPP

# include <sstream>
# include <iostream>
# include <cctype>
# include <string>
# include <algorithm>

bool		isChar(const std::string input);

bool		isInt(const std::string input);

bool		isFloat(const std::string input);

bool		isDouble(const std::string input);

bool		isInf(const std::string s);

bool		isInff(const std::string s);

bool		isNan(const std::string s);

bool		isNanf(const std::string s);

#endif