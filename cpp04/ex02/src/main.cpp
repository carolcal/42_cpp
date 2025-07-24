/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:52:22 by marvin            #+#    #+#             */
/*   Updated: 2025/07/21 14:52:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

void	testing_classes_objects(void)
{
	std::cout << PINK << "\n* TESTING DERIVED CLASSES AS OBJECTS *" << RESET << std::endl;
	std::cout << PINK << "\n* Constructors *" << RESET << std::endl;
	// Animal animal;
	Dog dog;
	Cat cat;

	std::cout << PINK << "\n* Getting Type *" << RESET << std::endl;
	std::cout << "dog type is: " << dog.getType() << std::endl;
	std::cout << "cat type is: " << cat.getType() << std::endl;

	std::cout << PINK << "\n* Make Sound *" << RESET << std::endl;
	std::cout << "dog sound: ";
	dog.makeSound();
	std::cout << "cat sound: ";
	cat.makeSound();

	std::cout << PINK << "\n* Destructors *" << RESET << std::endl;
};
// void	testing_classes_base_objects(void)
// {
// 	std::cout << PINK << "\n* TESTING DERIVED CLASSES AS BASE CLASS OBJECTS *" << RESET << std::endl;
// 	std::cout << PINK << "\n* Constructors *" << RESET << std::endl;
// 	const Animal animal = Animal();
// 	const Animal dog = Dog();
// 	const Animal cat = Cat();
// 	std::cout << PINK << "\n* Destructors *" << RESET << std::endl;
// };

void	testing_classes_pointers(void)
{
	std::cout << PINK << "\n* TESTING DERIVED CLASSES AS BASE CLASS POINTERS *" << RESET << std::endl;
	std::cout << PINK << "\n* Constructors *" << RESET << std::endl;
	// const Animal* animal = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout << PINK << "\n* Getting Type *" << RESET << std::endl;
	std::cout << "dog type is: " << dog->getType() << std::endl;
	std::cout << "cat type is: " << cat->getType() << std::endl;
	
	std::cout << PINK << "\n* Make Sound *" << RESET << std::endl;
	std::cout << "dog sound: ";
	dog->makeSound();
	std::cout << "cat sound: ";
	cat->makeSound();

	std::cout << PINK << "\n* Destructors *" << RESET << std::endl;
	// delete animal;
	delete dog;
	delete cat;
};

void	testing_array_brain(void)
{
	std::cout << PINK << "\n* TESTING BRAIN IN ARRAY *" << RESET << std::endl;

	std::cout << PINK << "\n* Constructors *" << RESET << std::endl;
	const int size = 6;
	Animal *animal[size];

	for (int i = 0; i < size; i++)
	{
		if (i % 2)
			animal[i] = new Dog();
		else
			animal[i] = new Cat();
	}

	std::cout << PINK << "\n* Setting Ideas *" << RESET << std::endl;
	for (int i = 0; i < size; i++)
	{
		if (animal[i]->getType() == "Dog")
		{
			std::cout << "Setting Dog's Ideas:" << std::endl;
			Dog* dog = dynamic_cast<Dog*>(animal[i]);
			if (dog)
			{
				dog->getBrain()->setIdea(0, "SLEEP");
				dog->getBrain()->setIdea(1, "BARK");
				dog->getBrain()->setIdea(2, "EAT");
				dog->getBrain()->setIdea(3, "ROLL");
			}
		}
		else
		{
			std::cout << "Setting Cat's Ideas:" << std::endl;
			Cat* cat = dynamic_cast<Cat*>(animal[i]);
			if (cat)
			{
				cat->getBrain()->setIdea(0, "PURR");
				cat->getBrain()->setIdea(1, "SLEEP");
				cat->getBrain()->setIdea(2, "LICK");
				cat->getBrain()->setIdea(3, "EAT");
			}
		}
	}

	std::cout << PINK << "\n* Getting Ideas *" << RESET << std::endl;
	for (int i = 0; i < size; i++)
	{
		std::cout << animal[i]->getType() << "'s Ideas:" << std::endl;
		if (animal[i]->getType() == "Dog")
		{
			Dog* dog = dynamic_cast<Dog*>(animal[i]);
			if (dog)
			{
				for (int j = 0; j < 4; j++)
					std::cout << "-> " << dog->getBrain()->getIdea(j) << std::endl;
			}
		}
		else
		{
			Cat* cat = dynamic_cast<Cat*>(animal[i]);
			if (cat)
			{
				for (int j = 0; j < 4; j++)
					std::cout << "-> " << cat->getBrain()->getIdea(j) << std::endl;
			}
		}
	}

	std::cout << PINK << "\n* Destructors *" << RESET << std::endl;
	for (int i = 0; i < size; i++)
	{
		delete animal[i];
	}
}

int main(void)
{
	testing_classes_objects();

	// std::cout << PINK << "\n------------------------------------------------------" << RESET << std::endl;
	
	// testing_classes_base_objects();
	
	std::cout << PINK << "\n------------------------------------------------------" << RESET << std::endl;
	
	testing_classes_pointers();

	std::cout << PINK << "\n------------------------------------------------------" << RESET << std::endl;
	
	testing_array_brain();

	return (0);
};