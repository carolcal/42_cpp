/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 13:14:33 by cayamash          #+#    #+#             */
/*   Updated: 2025/07/20 12:03:47 by marvin           ###   ########.fr       */
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
	protected:
		std::string _name;
		int         _hitPoints;
		int         _energyPoints;
		int         _attackDamage;

	public:
		/* ***** Constructors and Destructor **** */
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &other);
		~ClapTrap(void);

		/* ******** Assignment operator ********* */
		ClapTrap& operator=(const ClapTrap &other);
		
		/* ********** Method Functins *********** */
		void		attack(const std::string& target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);

		/* ************* Getters *************** */
		std::string getName(void);
        int			getHitPoints(void);
		int			getEnergyPoints(void);
		int			getAttackDamage(void);
		
		/* ************* Setters *************** */
		void		setName(std::string name);
		void		setHitPoints(int value);
		void		setEnergyPoints(int value);
		void		setAttackDamage(int value);
};

#endif