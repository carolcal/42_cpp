/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 12:08:37 by marvin            #+#    #+#             */
/*   Updated: 2025/07/20 12:08:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap
{
	public:
		/* ***** Constructors and Destructor **** */
		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(const FragTrap &other);
		~FragTrap(void);

		/* ******** Assignment operator ********* */
		FragTrap& operator=(const FragTrap &other);

		/* ********** Method Functins *********** */
		void highFivesGuys(void);
};

#endif