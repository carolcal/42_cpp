/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 13:46:52 by marvin            #+#    #+#             */
/*   Updated: 2025/07/20 13:46:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
    private:
        std::string _name;

    public:
        /* ***** Constructors and Destructor **** */
        DiamondTrap(void);
        DiamondTrap(std::string name);
        DiamondTrap(const DiamondTrap &other);
        ~DiamondTrap(void);

        /* ******** Assignment operator ********* */
        DiamondTrap& operator=(const DiamondTrap &other);

        /* ********** Method Functins *********** */
        void whoAmI(void);

        /* ************* Setters *************** */
        void	setName(std::string name);
};

#endif