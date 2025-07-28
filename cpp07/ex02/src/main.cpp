/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 14:18:26 by cayamash          #+#    #+#             */
/*   Updated: 2025/07/28 17:27:09 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Array.hpp>
#include <Array.tpp>

#include <cstdlib>

#define PINK "\033[35m"
#define RESET "\033[0m"

void	test_array_int(void)
{
	std::cout << PINK << "* TESTING ARRAY OF INTS *" << RESET << std::endl;
	
	std::cout << PINK << "\n* Empty Array: 'a' *" << RESET << std::endl;
	Array<int> a;
	std::cout << "Array 'a' size: " << a.size() << std::endl;

	std::cout << PINK << "\n* Array with 5 integers: 'b' *" << RESET << std::endl;
	Array<int> b(5);
	for (unsigned int i = 0; i < b.size(); i++)
		b[i] = i * 2;
	std::cout << "Array 'b' size: " << b.size() << std::endl;
	std::cout << "Array 'b': ";
	for (unsigned int i = 0; i < b.size(); i++)
		std::cout << b[i] << " ";
	std::cout << std::endl;

	std::cout << PINK << "\n* Copy Array 'b' into array 'c' *" << RESET << std::endl;
	Array<int> c(b);
	std::cout << "Array 'c' size: " << c.size() << std::endl;
	std::cout << "Array 'c': ";
	for (unsigned int i = 0; i < c.size(); i++)
		std::cout << c[i] << " ";
	std::cout << std::endl;

	std::cout << PINK << "\n* Assigning Array 'a' as equal to array 'b' *" << RESET << std::endl;
	a = b;
	std::cout << "Array 'a' size: " << a.size() << std::endl;
	std::cout << "Array 'a': ";
	for (unsigned int i = 0; i < a.size(); i++)
		std::cout << a[i] << " ";
	std::cout << std::endl;
}

void	test_array_string(void)
{
	std::cout << PINK << "\n* TESTING ARRAY OF STRINGS *" << RESET << std::endl;
	
	std::cout << PINK << "\n* Empty Array: 'd' *" << RESET << std::endl;
	Array<std::string> d;
	std::cout << "Array 'd' size: " << d.size() << std::endl;

	std::cout << PINK << "\n* Array with 5 strings: 'e' *" << RESET << std::endl;
	Array<std::string> e(5);
	e[0] = "tenha sempre uma toalha";
	e[1] = ",";
	e[2] = "não entre em pânico";
	e[3] = "e";
	e[4] = "senso de humor!";
	std::cout << "Array 'e' size: " << e.size() << std::endl;
	std::cout << "Array 'e': ";
	for (unsigned int i = 0; i < e.size(); i++)
		std::cout << e[i] << " ";
	std::cout << std::endl;

	std::cout << PINK << "\n* Assigning Array 'd' as equal to array 'e' *" << RESET << std::endl;
	d = e;
	std::cout << "Array 'd' size: " << d.size() << std::endl;
	std::cout << "Array 'd': ";
	for (unsigned int i = 0; i < d.size(); i++)
		std::cout << d[i] << " ";
	std::cout << std::endl;

	std::cout << PINK << "\n* Range exception in array 'e' *" << RESET << std::endl;
	try 
	{
		std::cout << e[10] << std::endl;
	} 
	catch (const std::out_of_range& ex) 
	{
		std::cerr << "Caught exception: " << ex.what() << std::endl;
	}
}

#define MAX_VAL 750
void	test_42(void)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return ;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;
}
int main()
{
	test_array_int();
	std::cout << PINK << "\n--------------------------------------------------------" << RESET << std::endl;
	test_array_string();
	std::cout << PINK << "\n--------------------------------------------------------" << RESET << std::endl;
	test_42();
}