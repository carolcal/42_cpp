/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 13:14:33 by cayamash          #+#    #+#             */
/*   Updated: 2025/07/18 16:48:54 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

# include <iostream>
# include <string>

#define RESET	"\033[0m"
#define PINK	"\033[35m"

class ClapTrap
{
	private:
		std::string _name;
		int         hitPoints;
		int         energyPoints;
		int         attackDamage;

	public:
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &other);
		~ClapTrap(void);

		ClapTrap& operator=(const ClapTrap &other);
		
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRapaired(unsigned int amount);
		void	setName(std::string name);
};

#endif