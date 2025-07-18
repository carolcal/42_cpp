/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 16:53:47 by cayamash          #+#    #+#             */
/*   Updated: 2025/07/08 10:25:07 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include <algorithm>

void	call_megaphone(const std::string& s)
{
	size_t	i = 0;
	while (i < s.length())
	{
		std::cout << static_cast<char>(std::toupper(s[i]));
		i++;
	}
}

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	int	i = 1;
	while(argv[i])
	{
		call_megaphone(argv[i]);
		i++;
	}
	std::cout << std::endl;
	return (0);
}