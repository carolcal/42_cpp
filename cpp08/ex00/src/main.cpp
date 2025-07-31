/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 21:10:00 by marvin            #+#    #+#             */
/*   Updated: 2025/07/29 21:10:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <stdexcept>

#define PINK "\033[35m"
#define RESET "\033[0m"

int main()
{
    try {
        std::cout << PINK << "* TESTING VECTOR *" << RESET << std::endl;
        int arr1[] = {1, 2, 3};
        std::cout <<"Creating vector v = {1, 2, 3}" << RESET << std::endl;
        std::vector<int> v(arr1, arr1 + 3);
        std::cout << "Searching number 2 in vector, index = " << easyfind(v, 2) << std::endl;

        std::cout << PINK << "\n* TESTING LIST *" << RESET << std::endl;
        int arr2[] = {4, 5, 6};
        std::cout <<"Creating list l = {4, 5, 6}" << RESET << std::endl;
        std::list<int> l(arr2, arr2 + 3);
        std::cout << "Searching number 6 in list, index = " << easyfind(l, 6) << std::endl;

        std::cout << PINK << "\n* TESTING DEQUE *" << RESET << std::endl;
        int arr3[] = {7, 8, 9};
        std::cout <<"Creating deque d = {7, 8, 9}" << RESET << std::endl;
        std::deque<int> d(arr3, arr3 + 3);
        std::cout << "Searching number 7 in deque, index =" << easyfind(d, 7) << std::endl;
    
        std::cout << PINK << "\n* THROWING ERROR *" << RESET << std::endl;
        std::cout << "Searching number 6 in vector: " << easyfind(v, 7) << std::endl;

    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}