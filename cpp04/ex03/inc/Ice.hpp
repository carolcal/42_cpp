/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 11:04:56 by cayamash          #+#    #+#             */
/*   Updated: 2025/07/22 11:15:51 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		/* ***** Constructors and Destructor **** */
		Ice(void);
		Ice(const Ice &other);
		~Ice(void);

		/* ******** Assignment operator ********* */
		Ice& operator=(const Ice &other);

		/* ********** Method Functins *********** */
		AMateria*	clone() const;
		void 		use(ICharacter &target);
};

#endif