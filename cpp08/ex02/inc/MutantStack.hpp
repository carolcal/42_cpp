/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 15:15:49 by cayamash          #+#    #+#             */
/*   Updated: 2025/08/07 10:28:48 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

# include <stack>
# include <deque>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	public:
		/* **** Constructors and Destructor **** */
		MutantStack(void) : std::stack<T, Container>() {};
		MutantStack(const MutantStack &other) : std::stack<T, Container>(other) {};
		~MutantStack(void) {};

		/* ************* Operators ************* */
		MutantStack<T>& operator=(const MutantStack &other)
		{
			if (this != &other)
				std::stack<T, Container>::operator=(other);
			return *this;
		};

		/* ********** Member Functions ********* */
		typedef typename std::stack<T, Container>::container_type::iterator iterator;
		iterator begin() { return this->c.begin(); }
		iterator end() { return this->c.end(); }

		typedef typename std::stack<T, Container>::container_type::const_iterator const_iterator;
		const_iterator cbegin() const {return this->c.begin(); }
		const_iterator cend() const { return this->c.end(); }

		typedef typename std::stack<T, Container>::container_type::reverse_iterator reverse_iterator;
		reverse_iterator rbegin() { return this->c.rbegin(); }
		reverse_iterator rend() { return this->c.rend(); }

		typedef typename std::stack<T, Container>::container_type::const_reverse_iterator const_reverse_iterator;
		const_reverse_iterator crbegin() const { return this->c.rbegin(); }
		const_reverse_iterator crend() const { return this->c.rend(); }
};

#endif