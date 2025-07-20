/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 16:59:29 by cayamash          #+#    #+#             */
/*   Updated: 2025/07/20 13:53:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SACVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap
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