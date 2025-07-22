/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:37:10 by cayamash          #+#    #+#             */
/*   Updated: 2025/07/22 18:10:13 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    private:
        static const int    _sourceSize = 4;
        AMateria*           _source[_sourceSize];

        void	MateriaSource::initArray(void);
    
    public:
		/* ***** Constructors and Destructor **** */
		MateriaSource(void);
		MateriaSource(const MateriaSource &other);
		~MateriaSource(void);
		
		/* ******** Assignment operator ********* */
		MateriaSource& operator=(const MateriaSource &other);

		/* ********** Method Functins *********** */
        void        learnMateria(AMateria* m);
	    AMateria*   createMateria(std::string const & type);
};

#endif