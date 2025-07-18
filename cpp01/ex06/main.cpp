/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 17:32:35 by cayamash          #+#    #+#             */
/*   Updated: 2025/07/15 11:00:46 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char *argv[])
{
    std::string red = "\033[1;31m";
    std::string end = "\033[0m";
    
    if (argc == 2)
    {
        std::cout << "Harl is going to complain about: "
            << red << argv[1] << end << std::endl;
        Harl* harl = new Harl();
        harl->complain(argv[1]);
        delete harl;
    }
    else
        std::cout << "Usage: ./harlFilter <complain>" << std::endl;
    return (0);
}