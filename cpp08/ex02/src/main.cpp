/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 17:36:13 by cayamash          #+#    #+#             */
/*   Updated: 2025/07/30 18:48:17 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

#include <iostream>
#include <list>
#include <vector>
#include <string>

#define PINK "\033[35m"
#define RESET "\033[0m"

void test_subject()
{
	std::cout << PINK << "* Subject Test (int) *" << RESET << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << " ";
		++it;
	}
	std::stack<int> s(mstack);

	std::cout << "\n* Creating cstack: (constant) *" << std::endl;
	const MutantStack<int> cstack = mstack;
	std::cout << "Is empty? " << ((cstack.empty() == 1) ? "yes" : "no") << std::endl;
	MutantStack<int>::const_iterator cit = mstack.cbegin();
	MutantStack<int>::const_iterator cite = mstack.cend();
	while (cit != cite)
	{
		std::cout << *cit << " ";
		++cit;
	}
	std::cout << std::endl;
}
void test_list()
{
	std::cout << PINK << "\n* List Test *" << RESET << std::endl;
	MutantStack<char, std::list<char> >	mstack;
	std::cout << "Is empty? " << ((mstack.empty() == 1) ? "yes" : "no") << std::endl;
	std::cout << "Pushing elements... " << std::endl;
	mstack.push('f');
	mstack.push('o');
	mstack.push('r');
	mstack.push('t');
	mstack.push('y');
	mstack.push(' ');
	mstack.push('t');
	mstack.push('w');
	mstack.push('o');
	std::cout << "Is empty? " << ((mstack.empty() == 1) ? "yes" : "no") << std::endl;
	std::cout << "Stack: ";
	MutantStack<char, std::list<char> >::iterator	it = mstack.begin();
	MutantStack<char, std::list<char> >::iterator	ite = mstack.end();
	while (it != ite) {
		std::cout << *it;
		it++;
	}
	std::cout << std::endl;
	std::cout << "size: " << mstack.size() << std::endl;
	std::cout << "top element: " << mstack.top() << std::endl;
	
	std::cout << "* Pop top element *" << std::endl;
	mstack.pop();
	std::cout << "new size: " << mstack.size() << std::endl;
	std::cout << "new top element: " << mstack.top() << std::endl;

	std::cout << "* Creating cstack: (constant) *" << std::endl;
	const MutantStack<char, std::list<char> > cstack = mstack;
	std::cout << "Is empty? " << ((cstack.empty() == 1) ? "yes" : "no") << std::endl;
	MutantStack<char, std::list<char> >::const_iterator cit = cstack.cbegin();
	MutantStack<char, std::list<char> >::const_iterator cite = cstack.cend();
	std::cout << "Stack: ";
	while (cit != cite)
	{
		std::cout << *cit;
		++cit;
	}
	std::cout << std::endl;
}
void test_vector()
{
	std::cout << PINK << "\n* Vector int *" << RESET << std::endl;
	MutantStack<int, std::vector<int> >	mstack;
	std::cout << "Is empty? " << ((mstack.empty() == 1) ? "yes" : "no") << std::endl;
	std::cout << "Pushing elements... " << std::endl;
	mstack.push(2);
	mstack.push(0);
	mstack.push(2);
	mstack.push(5);
	std::cout << "Is empty? " << ((mstack.empty() == 1) ? "yes" : "no") << std::endl;
	std::cout << "Reverse iterate stack: ";
	MutantStack<int, std::vector<int> >::reverse_iterator	revIt = mstack.rbegin();
	MutantStack<int, std::vector<int> >::reverse_iterator	revIte = mstack.rend();
	while (revIt != revIte) {
		std::cout << *revIt;
		revIt++;
	}
	std::cout << std::endl;
	std::cout << "size: " << mstack.size() << std::endl;
	std::cout << "top element: " << mstack.top() << std::endl;
	
	std::cout << "* Pop top element *" << std::endl;
	mstack.pop();
	std::cout << "new size: " << mstack.size() << std::endl;
	std::cout << "top element: " << mstack.top() << std::endl;

	std::cout << "* Creating cstack: (constant) *" << std::endl;
	const MutantStack<int, std::vector<int> > cstack = mstack;
	std::cout << "Is empty? " << ((cstack.empty() == 1) ? "yes" : "no") << std::endl;
	MutantStack<int, std::vector<int> >::const_reverse_iterator cit = cstack.crbegin();
	MutantStack<int, std::vector<int> >::const_reverse_iterator cite = cstack.crend();
	std::cout << "Stack: ";
	while (cit != cite)
	{
		std::cout << *cit;
		++cit;
	}
	std::cout << std::endl;
}
void test_string()
{
	std::cout << PINK << "\n* String stack *" << RESET << std::endl;
	std::cout << "Creating mstack1: " << std::endl;
	MutantStack<std::string>	mstack1;
	std::cout << "Is empty? " << ((mstack1.empty() == 1) ? "yes" : "no") << std::endl;
	std::cout << "Pushing elements... " << std::endl;
	mstack1.push("always have a towel");
	mstack1.push("don't panic!");

	std::cout << "Is empty? " << ((mstack1.empty() == 1) ? "yes" : "no") << std::endl;
	std::cout << "Creating mstack2: " << std::endl;
	MutantStack<std::string>	mstack2(mstack1);
	std::cout << "Is empty? " << ((mstack1.empty() == 1) ? "yes" : "no") << std::endl;
	std::cout << "Pushing more elements... " << std::endl;
	mstack2.push("sense of humor");

	std::cout << "MutantStack1 size: " << mstack1.size() << std::endl;
	std::cout << "MutantStack2 size: " << mstack2.size() << std::endl;
	
	std::cout << "* Pop elements from MutantStack1 *" << std::endl;
	mstack1.pop();
	std::cout << "MutantStack1 size: " << mstack1.size() << std::endl;
	std::cout << "MutantStack2 size: " << mstack2.size() << std::endl;

	std::cout << "* Pop elements from MutantStack2 *" << std::endl;
	mstack2.pop();
	std::cout << "MutantStack1 size: " << mstack1.size() << std::endl;
	std::cout << "MutantStack2 size: " << mstack2.size() << std::endl;
}

int main()
{
	test_subject();
	test_list();
	test_vector();
	test_string();
	return 0;
}