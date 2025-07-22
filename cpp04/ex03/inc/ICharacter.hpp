/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 10:31:00 by cayamash          #+#    #+#             */
/*   Updated: 2025/07/22 18:23:27 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

# include "AMateria.hpp"

class ICharacter
{
	public:
	virtual ~ICharacter() {}
	virtual std::string const & getName() const = 0;
	virtual void	equip(AMateria* m) = 0;
	virtual void 	unequip(int idx) = 0;
	virtual void 	use(int idx, ICharacter& target) = 0;
};

#endif