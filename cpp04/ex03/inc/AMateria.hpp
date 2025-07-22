/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 10:22:50 by cayamash          #+#    #+#             */
/*   Updated: 2025/07/22 11:28:08 by cayamash         ###   ########.fr       */
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
	~AMateria(void);

	/* ******** Assignment operator ********* */
	AMateria& operator=(const AMateria &other);

	/* ********** Method Functins *********** */
	std::string const & getType() const;

	/* ********** Virtual Functins ********** */
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

#endif