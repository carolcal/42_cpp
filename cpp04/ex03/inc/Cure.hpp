/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 11:17:47 by cayamash          #+#    #+#             */
/*   Updated: 2025/07/22 11:18:03 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		/* ***** Constructors and Destructor **** */
		Cure(void);
		Cure(const Cure &other);
		~Cure(void);

		/* ******** Assignment operator ********* */
		Cure& operator=(const Cure &other);

		/* ********** Method Functins *********** */
		AMateria*	clone() const;
		void 		use(ICharacter &target);
};

#endif