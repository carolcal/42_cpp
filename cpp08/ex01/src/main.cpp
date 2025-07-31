/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 14:12:20 by cayamash          #+#    #+#             */
/*   Updated: 2025/07/30 15:01:27 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#define PINK "\033[35m"
#define RESET "\033[0m"

void test_subject()
{
	std::cout << PINK << "* Subject Test *" << RESET << std::endl;
	Span sp = Span(5);
	std::cout << "Span 'sp' size: " << sp.size() << std::endl;
	try
	{
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "Added 5 numbers." << std::endl;
		sp.addNumber(2); //should throw an exception;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
}

void test_span_one()
{
	std::cout << PINK << "\n* Test Span size 1 *" << RESET << std::endl;
	Span a(1);
	std::cout << "Span 'a' size: " << a.size() << std::endl;
	
	try
	{
		a.addNumber(8);
		std::cout << "Added 1 number." << std::endl;
		a.addNumber(2); //should throw exception
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		std::cout << "Shortest Span: " << a.shortestSpan() << std::endl; //should throw exception
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		std::cout << "Longest Span: " << a.longestSpan() << std::endl; //should throw exception
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void test_span_big()
{
	std::cout << PINK << "\n* Test Span size 12000 *" << RESET << std::endl;
	Span b(12000);
	std::cout << "Span 'b' size: " << b.size() << std::endl;
	
	try
	{
		b.populate(12000);
		std::cout << "Added 12000 numbers." << std::endl;
		b.populate(7); //should thow exception
		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "Shortest Span: " << b.shortestSpan() << std::endl;
	std::cout << "Longest Span: " << b.longestSpan() << std::endl;
}


int main()
{	
	test_subject();
	std::cout << PINK << "\n------------------------------------------" << RESET << std::endl;
	test_span_one();
	std::cout << PINK << "\n------------------------------------------" << RESET << std::endl;
	test_span_big();
	return 0;
}