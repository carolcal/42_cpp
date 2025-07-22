/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 16:59:29 by cayamash          #+#    #+#             */
/*   Updated: 2025/07/22 15:30:51 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
    public:
		/* ***** Constructors and Destructor **** */
		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &other);
		~ScavTrap(void);

		/* ******** Assignment operator ********* */
		ScavTrap& operator=(const ScavTrap &other);

		/* ********** Method Functins *********** */
		void	attack(const std::string& target);
		void	guardGate(void);
};

#endif