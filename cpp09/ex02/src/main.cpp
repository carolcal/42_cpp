/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 12:02:59 by cayamash          #+#    #+#             */
/*   Updated: 2025/08/07 17:36:09 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char *av[])
{
	if (ac < 2)
	{
		std::cerr << "Usage: ./PmergeMe <positive_numbers_sequence>" << std::endl;
		return 1;
	}
	try
	{
		PmergeMe sort;
		sort.parseInput(ac, av);
		sort.sortVector();
		sort.sortDeque();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return 2;
	}
	return 0;
}