/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 12:02:13 by cayamash          #+#    #+#             */
/*   Updated: 2025/08/07 18:20:35 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

# include <set>
# include <vector>
# include <deque>
# include <iostream>
# include <sstream>
# include <ctime>
# include <iomanip>

# define RESET	"\033[0m"
# define PINK	"\033[35m"

class PmergeMe
{
	private:
		std::string         _input;
		std::vector<int>    _vec;
		std::deque<int>     _deq;

	public:
		PmergeMe(void);
		PmergeMe(const PmergeMe &other);
		~PmergeMe(void);
		
		PmergeMe& operator=(const PmergeMe &other);
		
		void    parseInput(int ac, char *av[]);
		void    sortVector(void);
		void    sortDeque(void);
		
};

template <typename Container>
void	insertBynarySearch(Container &larger, Container &smaller)
{
	for (size_t i = 0; i < smaller.size(); ++i)
	{
		typename Container::iterator pos = std::lower_bound(larger.begin(), larger.end(), smaller[i]);
		larger.insert(pos, smaller[i]);
	}
};

template <typename Container>
void	mergeInsertionSort(Container &container)
{
	size_t		i = 0;
	size_t		n = container.size();
	Container   larger;
	Container   smaller;

	if (n <= 1)
		return ;
	while (i + 1 < n)
	{
		if (container[i] > container[i + 1])
		{
			larger.push_back(container[i]);
			smaller.push_back(container[i + 1]);
		}
		else
		{
			larger.push_back(container[i + 1]);
			smaller.push_back(container[i]);
		}
		i += 2;
	}
	if (i < n)
		larger.push_back(container[i]);
	mergeInsertionSort(larger);
	insertBynarySearch(larger, smaller);
	container = larger;
};

template <typename Container>
bool	isSorted(Container &container)
{
	size_t		n = container.size();
	int			larger_num = container[0];
	
	if (n <= 1)
		return true;
	for (size_t i = 1; i < n; i++)
	{
		if (container[i] < container[i - 1] || container[i] < larger_num)
			return false;
		larger_num = container[i];
	}
	return true;
};

template <typename Container>
void	printContainer(Container &container)
{
	for (size_t i = 0; i < container.size(); ++i)
	{
		std::cout << container[i] << " ";
	}
	std::cout << std::endl;
};

#endif