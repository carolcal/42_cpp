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
	Animal animal;
	Animal bear("Bear");
	Dog dog;
	Cat cat;
	WrongAnimal wrongAnimal;
	WrongCat wrongCat;

	std::cout << PINK << "\n* Getting Type *" << RESET << std::endl;
	std::cout << "animal type is: " << animal.getType() << std::endl;
	std::cout << "bear type is: " << bear.getType() << std::endl;
	std::cout << "dog type is: " << dog.getType() << std::endl;
	std::cout << "cat type is: " << cat.getType() << std::endl;
	std::cout << "wrongAnimal type is: " << wrongAnimal.getType() << std::endl;
	std::cout << "wrongCat type is: " << wrongCat.getType() << std::endl;

	std::cout << PINK << "\n* Make Sound *" << RESET << std::endl;
	std::cout << "animal sound: ";
	animal.makeSound();
	std::cout << "bear sound: ";
	bear.makeSound();
	std::cout << "dog sound: ";
	dog.makeSound();
	std::cout << "cat sound: ";
	cat.makeSound();
	std::cout << "wrongAnimal sound: ";
	wrongAnimal.makeSound();
	std::cout << "wrongCat sound: ";
	wrongCat.makeSound();
	std::cout << "=> Each object is instantiated as its respective class." << std::endl;

	std::cout << PINK << "\n* Destructors *" << RESET << std::endl;
};
void	testing_classes_base_objects(void)
{
	std::cout << PINK << "\n* TESTING DERIVED CLASSES AS BASE CLASS OBJECTS *" << RESET << std::endl;
	std::cout << PINK << "\n* Constructors *" << RESET << std::endl;
	const Animal animal = Animal();
	const Animal dog = Dog();
	const Animal cat = Cat();
	const WrongAnimal wrongAnimal = WrongAnimal();
	const WrongAnimal wrongCat = WrongCat();

	std::cout << PINK << "\n* Getting Type *" << RESET << std::endl;
	std::cout << "animal type is: " << animal.getType() << std::endl;
	std::cout << "dog type is: " << dog.getType() << std::endl;
	std::cout << "cat type is: " << cat.getType() << std::endl;
	std::cout << "wrongAnimal type is: " << wrongAnimal.getType() << std::endl;
	std::cout << "wrongCat type is: " << wrongCat.getType() << std::endl;
	
	std::cout << PINK << "\n* Make Sound *" << RESET << std::endl;
	std::cout << "animal sound: ";
	animal.makeSound();
	std::cout << "dog sound: ";
	dog.makeSound();
	std::cout << "cat sound: ";
	cat.makeSound();
	std::cout << "wrongAnimal sound: ";
	wrongAnimal.makeSound();
	std::cout << "wrongCat sound: ";
	wrongCat.makeSound();
	std::cout << "=> Each object is instantiated as the base class, the derived class is sliced." << std::endl;
	
	std::cout << PINK << "\n* Destructors *" << RESET << std::endl;
};

void	testing_classes_pointers(void)
{
	std::cout << PINK << "\n* TESTING DERIVED CLASSES AS BASE CLASS POINTERS *" << RESET << std::endl;
	std::cout << PINK << "\n* Constructors *" << RESET << std::endl;
	const Animal* animal = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	const WrongAnimal *wrongAnimal = new WrongAnimal();
	const WrongAnimal *wrongCat = new WrongCat();

	std::cout << PINK << "\n* Getting Type *" << RESET << std::endl;
	std::cout << "animal type is: " << animal->getType() << std::endl;
	std::cout << "dog type is: " << dog->getType() << std::endl;
	std::cout << "cat type is: " << cat->getType() << std::endl;
	std::cout << "wrongAnimal type is: " << wrongAnimal->getType() << std::endl;
	std::cout << "wrongCat type is: " << wrongCat->getType() << std::endl;
	
	std::cout << PINK << "\n* Make Sound *" << RESET << std::endl;
	std::cout << "animal sound: ";
	animal->makeSound();
	std::cout << "dog sound: ";
	dog->makeSound();
	std::cout << "cat sound: ";
	cat->makeSound();
	std::cout << "wrongAnimal sound: ";
	wrongAnimal->makeSound();
	std::cout << "wrongCat sound: ";
	wrongCat->makeSound();
	std::cout << "=> The correct function is called for each object using the vtable." << std::endl;

	std::cout << PINK << "\n* Destructors *" << RESET << std::endl;
	delete animal;
	delete dog;
	delete cat;
	delete wrongAnimal;
	delete wrongCat;
};
int main(void)
{
	testing_classes_objects();

	std::cout << PINK << "\n------------------------------------------------------" << RESET << std::endl;
	
	testing_classes_base_objects();
	
	std::cout << PINK << "\n------------------------------------------------------" << RESET << std::endl;
	
	testing_classes_pointers();

	return (0);
};