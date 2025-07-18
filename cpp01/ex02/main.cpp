/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 14:13:45 by cayamash          #+#    #+#             */
/*   Updated: 2025/07/11 14:22:43 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string.h>

int main()
{
    std::string s = "HI THIS IS BRAIN";
    std::string* stringPTR = &s;
    std::string& stringREF = s;
    
    std::cout << "Memory address to the string variable: " << &s << std::endl;
    std::cout << "Memory address to the stringPTR variable: " << &stringPTR << std::endl;
    std::cout << "Memory address to the stringREF variable: " << &stringREF << std::endl;
    
    std::cout << "Value of the string variable: " << s << std::endl;
    std::cout << "Value of the stringPTR variable: " << stringPTR << std::endl;
    std::cout << "Value of the stringREF variable: " << stringREF << std::endl;
}