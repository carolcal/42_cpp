/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 12:02:11 by cayamash          #+#    #+#             */
/*   Updated: 2025/08/07 17:55:59 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) {};

PmergeMe::PmergeMe(const PmergeMe &other) 
{
	_input = other._input;
	*this = other;
};

PmergeMe::~PmergeMe(void) {};

PmergeMe&	PmergeMe::operator=(const PmergeMe &other)
{
	if ( this != &other)
	{
		*this = other;
		_input = other._input;
	};
	return *this;
};

void	PmergeMe::parseInput(int ac, char *av[])
{
	std::set<int> nums;

	for (int i = 1; i < ac; i++)
	{
		int					num;
		std::string			curr = av[i];
		std::istringstream	iss(curr);
		
		iss >> num;
		if (iss.fail() || !iss.eof() || num <= 0)
			throw std::invalid_argument("Bad Input: insert positive integer numbers: " + curr);
		if (nums.find(num) != nums.end())
			throw std::invalid_argument("Bad Input: duplicated number: " + curr);
		
		nums.insert(num);
		_vec.push_back(num);
		_deq.push_back(num);
	}
	std::cout << PINK << "Before: " << RESET;
	printContainer(_vec);
};

void	PmergeMe::sortVector(void)
{
	double			time = 0;
	std::clock_t	start;
	std::clock_t	end;

	if(!isSorted(_vec))
	{
		start = clock();
		mergeInsertionSort(_vec);
		end = clock();
		if(!isSorted(_vec))
			throw std::runtime_error("Failed when sorting vector container");
		time = static_cast<double>(end - start) * 1000 / CLOCKS_PER_SEC;
	}
	std::cout << PINK << "After: " << RESET;
	printContainer(_vec);
	std::cout << "Time to process a range of " << _vec.size()
		<< " elements with std::vector : " << std::setprecision(6)
		<< PINK << time << " us." << RESET << std::endl;
};
			  
void	PmergeMe::sortDeque(void)
{
	double			time = 0;
	std::clock_t	start;
	std::clock_t	end;

	if(!isSorted(_deq))
	{
		start = clock();
		mergeInsertionSort(_deq);
		end = clock();
		if(!isSorted(_deq))
			throw std::runtime_error("Failed when sorting deque container");
		time = static_cast<double>(end - start) * 1000 / CLOCKS_PER_SEC;
	}
	std::cout << "Time to process a range of " << _deq.size()
		<< " elements with std::deque : " << std::setprecision(6)
		<< PINK << time << " us." << RESET << std::endl;
};