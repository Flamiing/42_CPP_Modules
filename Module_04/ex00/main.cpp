/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 17:38:40 by alaaouam          #+#    #+#             */
/*   Updated: 2023/07/23 14:22:10 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int main(void)
{
	Animal* animal = new Animal();
	Animal* dog = new Dog();
	Animal* cat = new Cat();
	
	WrongAnimal* wrongAnimal = new WrongAnimal();
	WrongAnimal* wrongCat = new WrongCat();
	
	std::cout << "I am a " << dog->getType() << " 🐶" << std::endl;
	std::cout << "I am a " << cat->getType() << " 🐱" << std::endl;
	std::cout << "I am an " << animal->getType() << std::endl;

	std::cout << "I am a " << wrongCat->getType() << " 🐱" << std::endl;
	std::cout << "I am a " << wrongAnimal->getType() << std::endl;
	
	dog->makeSound();
	cat->makeSound();
	animal->makeSound();

	wrongCat->makeSound();
	wrongAnimal->makeSound();
	
	delete animal;
	delete dog;
	delete cat;
	delete wrongCat;
	delete wrongAnimal;
	
	return 0;
}