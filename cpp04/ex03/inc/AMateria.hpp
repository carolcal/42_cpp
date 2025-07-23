/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 10:22:50 by cayamash          #+#    #+#             */
/*   Updated: 2025/07/23 08:01:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"

class AMateria
{
	protected:
		const std::string _type;

	public:
	/* ***** Constructors and Destructor **** */
	AMateria(void);
	AMateria(std::string const & type);
	AMateria(const AMateria &other);
	virtual ~AMateria(void);

	/* ******** Assignment operator ********* */
	AMateria& operator=(const AMateria &other);

	/* ********** Method Functins *********** */
	std::string const & getType() const;

	/* ********** Virtual Functins ********** */
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

#endif