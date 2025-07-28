/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 11:33:40 by cayamash          #+#    #+#             */
/*   Updated: 2025/07/28 12:16:29 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <string>

# define RESET	"\033[0m"
# define PINK	"\033[35m"

//Function to deal with ints
void	increment(int &n) { n++; };

//Function to deal with floats
void	doubleValue(float &f) { f *= 2; };

//Function to deal with strings
void	toUpper(std::string &s)
{
	int len = s.length();
	for (int i = 0; i < len; i++)
		s[i] = std::toupper(s[i]);
}

//Function to deal with print it all
template <typename T>
void	print(T &value) { std::cout << value << " "; };

int	main()
{
	std::cout << PINK << "* Testing int array *" << RESET << std::endl;
	int	a[5] = {1, 2, 3, 4, 5};
	std::cout << "Original Array: "; 
	iter(a, 5, print);
	std::cout << std::endl;
	iter(a, 5, increment);
	std::cout << "Array after iter: ";
	iter(a, 5, print);
	std::cout << std::endl;

	std::cout << PINK << "\n* Testing float array *" << RESET << std::endl;
	float	b[5] = {1.2, 3.4, 5.6, 7.8, 9.0};
	std::cout << "Original Array: "; 
	iter(b, 5, print);
	std::cout << std::endl;
	iter(b, 5, doubleValue);
	std::cout << "Array after iter: ";
	iter(b, 5, print);
	std::cout << std::endl;

	std::cout << PINK << "\n* Testing string array *" << RESET << std::endl;
	std::string	c[5] = {"tenha sempre uma toalha", ",", "não entre em pânico", "e", "senso de humor!" };
	std::cout << "Original Array: "; 
	iter(c, 5, print);
	std::cout << std::endl;
	iter(c, 5, toUpper);
	std::cout << "Array after iter: ";
	iter(c, 5, print);
	std::cout << std::endl;

	return 0;
}

