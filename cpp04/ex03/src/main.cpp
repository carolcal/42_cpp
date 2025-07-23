/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 18:13:17 by cayamash          #+#    #+#             */
/*   Updated: 2025/07/23 09:48:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

#include <iostream>
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

#define PINK "\033[35m"
#define RESET "\033[0m"

void testMateriaSource(void)
{
	std::cout << PINK << "\n* TEST MATERIA SOURCE: *" << RESET << std::endl;

	std::cout << PINK << "\n* Constructor *" << RESET << std::endl;
	IMateriaSource* src = new MateriaSource();

	std::cout << PINK << "\n* Learn Materias *" << RESET << std::endl;
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	std::cout << PINK << "\n* Trying to learn a fifth materia (should fail): *" << RESET << std::endl;
	src->learnMateria(new Ice());

	std::cout << PINK << "\n* Creating learned materias: *" << RESET << std::endl;
	AMateria* m1 = src->createMateria("ice");
	AMateria* m2 = src->createMateria("cure");

	std::cout << PINK << "\n* Trying to create unknown materia type 'fire': *" << RESET << std::endl;
	AMateria* m3 = src->createMateria("fire");

	std::cout << PINK << "\n* Copy Constructor *" << RESET << std::endl;
	MateriaSource src_copy(*(dynamic_cast<MateriaSource*>(src)));

	std::cout << PINK << "\n* Check if copied Materias *" << RESET << std::endl;
	AMateria* c1 = src_copy.createMateria("ice");
	AMateria* c2 = src_copy.createMateria("cure");
	AMateria* c3 = src->createMateria("fire");
	
	std::cout << PINK << "\n* Destructors *" << RESET << std::endl;
	delete m1;
	delete m2;
	delete m3;
	delete c1;
	delete c2;
	delete c3;
	delete src;
}

void testCharacter(void)
{
	std::cout << PINK << "\n* TEST CHARACTER *" << RESET << std::endl;

	std::cout << PINK << "\n* Constructor *" << RESET << std::endl;
	Character* me = new Character("me");
	Character* bob = new Character("bob");

	std::cout << PINK << "\n* Equip *" << RESET << std::endl;
	me->equip(new Ice());
	me->equip(new Cure());
	me->equip(new Ice());
	me->equip(new Cure());

	std::cout << PINK << "\nTrying to equip a 5th materia (should fail):" << RESET << std::endl;
	me->equip(new Ice());

	std::cout << PINK << "\nUsing all equipped materias:" << RESET << std::endl;
	for (int i = 0; i < 4; i++)
		me->use(i, *bob);

	std::cout << PINK << "\nTrying to use an invalid slot (should do nothing):" << RESET << std::endl;
	me->use(4, *bob);

	std::cout << PINK << "\n* Unequip *" << RESET << std::endl;
	for (int i = 0; i < 4; i++)
		me->unequip(i);

	std::cout << PINK << "\nTrying to use after unequipping (should do nothing):" << RESET << std::endl;
	for (int i = 0; i < 4; i++)
		me->use(i, *bob);

	std::cout << PINK << "\n* Copy Constructor (should copy inventory) *" << RESET << std::endl;
	Character copy(*me);
	copy.equip(new Ice());
	copy.use(0, *bob); // deve funcionar

	std::cout << PINK << "\n* Assignment Operator (should not copy inventory) *" << RESET << std::endl;
	Character assign;
	assign = *bob;
	assign.use(0, *me);

	std::cout << PINK << "\n* Destructors *" << RESET << std::endl;
	delete me;
	delete bob;
}


void testSubject(void)
{
	std::cout << PINK << "\n* TEST SUBJECT *" << RESET << std::endl;

	std::cout << PINK << "\n* Create Materia Source *" << RESET << std::endl;
	IMateriaSource* src = new MateriaSource();

	std::cout << PINK << "\n* LearnMaterias *" << RESET << std::endl;
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	std::cout << PINK << "\n* Create Character 'me' *" << RESET << std::endl;
	ICharacter* me = new Character("me");
	AMateria* tmp;

	std::cout << PINK << "\n* Create Materias and Equip Character *" << RESET << std::endl;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	
	std::cout << PINK << "\n* Create Character 'bob' *" << RESET << std::endl;
	ICharacter* bob = new Character("bob");

	std::cout << PINK << "\n* Use Materias *" << RESET << std::endl;
	me->use(0, *bob);
	me->use(1, *bob);

	std::cout << PINK << "\n* Destroy everything *" << RESET << std::endl;
	delete bob;
	delete me;
	delete src;
}

int main()
{
	testMateriaSource();
	std::cout << PINK << "\n------------------------------------------------------" << RESET << std::endl;
	testCharacter();
	std::cout << PINK << "\n------------------------------------------------------" << RESET << std::endl;
	testSubject();
	return 0;
}