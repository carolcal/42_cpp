/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 13:14:33 by cayamash          #+#    #+#             */
/*   Updated: 2025/07/19 15:52:36 by marvin           ###   ########.fr       */
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
		int         _hitPoints;
		int         _energyPoints;
		int         _attackDamage;

	public:
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &other);
		~ClapTrap(void);

		ClapTrap& operator=(const ClapTrap &other);
		
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

        std::string getName(void);
        int			getHitPoints(void);
		int			getEnergyPoints(void);
		int			getAttackDamage(void);

		void		setName(std::string name);
		void		setHitPoints(int value);
		void		setEnergyPoints(int value);
		void		setAttackDamage(int value);
};

#endif