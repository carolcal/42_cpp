/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:39:44 by cayamash          #+#    #+#             */
/*   Updated: 2025/07/22 18:12:47 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

/* *********************** Constructors and Destructor ********************** */
MateriaSource::MateriaSource(void) 
{
	initArray();
};

MateriaSource::MateriaSource(const MateriaSource &other)
{
	initArray();
    *this = other;
};

MateriaSource::~MateriaSource(void) 
{
	for (int i = 0; i < _sourceSize; i++)
		delete _source[i];
};

/* *************************** Assignment operator ************************** */
MateriaSource& MateriaSource::operator=(const MateriaSource &other)
{
    if (this != &other)
    {
        for (int i = 0; i < _sourceSize; i++)
		{
			delete _source[i];
			_source[i] = NULL;
			if (other._source[i])
				_source[i] = other._source[i]->clone();
		}   
    }
    return *this;
};

/* **************************** Method Functions *************************** */
void		MateriaSource::learnMateria(AMateria* m)
{
	if (!m)
	{
		std::cout << "Materia does not exist!" << std::endl;
	}
	for (int i = 0; i < _sourceSize; i++)
	{
		if (_source[i] == NULL)
		{
			_source[i] = m;
			std::cout << "Learned new materia of type" 
				<< m->getType() << std::endl;
			return ;
		}
	}
	std::cout << "Source is full, cannot learn new materia!" << std::endl;
};

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < _sourceSize; i++)
	{
		if (_source[i] && _source[i]->getType() == type)
			return _source[i]->clone();
	}

	std::cerr << "Type not found. Unable to create materia of type " 
		<< type << std::endl;
};

void	MateriaSource::initArray(void)
{
	for (int i = 0; i < _sourceSize; i++)
		_source[i] = NULL;
};