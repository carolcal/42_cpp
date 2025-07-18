/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 16:35:48 by cayamash          #+#    #+#             */
/*   Updated: 2025/07/14 17:48:26 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	std::cout << "Harl has arrived at the burger place." << std::endl;
}

Harl::~Harl()
{
	std::cout << "Harl left screaming dissatisfaction." << std::endl;
}

void	Harl::debug(void)
{
    std::cout 
        << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" 
        << std::endl;
}

void	Harl::info(void)
{
    std::cout
        << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
        << std::endl;
}

void	Harl::warning(void)
{
    std::cout
        << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month."
        << std::endl;
}

void	Harl::error(void)
{
    std::cout
        << "This is unacceptable! I want to speak to the manager now."
        << std::endl;
}

void	Harl::complain(std::string level)
{
	int	i = 0;
    typedef void (Harl::*HarlFuntion)();
	
	HarlFuntion functions[] = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};
	std::string levels[] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};
	
	while (i < 4 && levels[i] != level)
		i++;
	if (levels[i] == level)
		(this->*functions[i])();
	else
		std::cerr 
			<< "Harl is confused, this level doesn't exists for him!" 
			<< std::endl;
}