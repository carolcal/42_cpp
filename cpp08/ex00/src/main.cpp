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
        int arr1[] = {1, 2, 3};
        std::vector<int> v(arr1, arr1 + 3);
        std::cout << "vector: " << easyfind(v, 2) << std::endl;

        int arr2[] = {4, 5, 6};
        std::list<int> l(arr2, arr2 + 3);
        std::cout << "list: " << easyfind(l, 6) << std::endl;

        int arr3[] = {7, 8, 9};
        std::deque<int> d(arr3, arr3 + 3);
        std::cout << "deque: " << easyfind(d, 7) << std::endl;
    }
    catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}