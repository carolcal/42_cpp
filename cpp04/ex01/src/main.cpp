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

int main()
{
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

	return (0);
}