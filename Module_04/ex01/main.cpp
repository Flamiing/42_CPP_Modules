/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 17:38:40 by alaaouam          #+#    #+#             */
/*   Updated: 2023/07/27 17:54:56 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"
#include "Brain.hpp"

int main(void)
{
	Dog* dog1 = new Dog();
	dog1->changeIdea(0, "\"I love eating\"");
	Dog* dog2 = new Dog(*dog1);
	dog2->changeIdea(0, "\"I love drinking\"");
	Cat* cat1 = new Cat();
	cat1->changeIdea(0, "\"I love eating\"");
	Cat* cat2 = new Cat(*cat1);
	cat2->changeIdea(0, "\"I love drinking\"");

	std::cout << std::endl;

	std::cout << "The Dog 1 thinks: " << dog1->thinkIdea(0) << std::endl;
	std::cout << "The Dog 2 thinks: " << dog2->thinkIdea(0) << std::endl;
	std::cout << "The Cat 1 thinks: " << cat1->thinkIdea(0) << std::endl;
	std::cout << "The Cat 2 thinks: " << cat2->thinkIdea(0) << std::endl;
	
	std::cout << std::endl;

	Dog *randomDog1 = new Dog();
	Dog randomDog2;
	
	randomDog1->changeIdea(0, "\"I love eating\"");
	randomDog2 = *randomDog1;
	randomDog1->changeIdea(0, "\"I love sleeping\"");
	std::cout << "I am a " << randomDog2.getType() << " 🐶" << std::endl;
	std::cout << "The randomDog 1 thinks: " << randomDog1->thinkIdea(0) << std::endl;
	std::cout << "The randomDog 2 thinks: " << randomDog2.thinkIdea(0) << std::endl;
	
	std::cout << std::endl;
	
	Cat *randomCat1 = new Cat();
	Cat randomCat2;
	
	randomCat1->changeIdea(0, "\"I love eating\"");
	randomCat2 = *randomCat1;
	randomCat1->changeIdea(0, "\"I love sleeping\"");
	std::cout << "I am a " << randomCat2.getType() << " 🐱" << std::endl;
	std::cout << "The randomCat 1 thinks: " << randomCat1->thinkIdea(0) << std::endl;
	std::cout << "The randomCat 2 thinks: " << randomCat2.thinkIdea(0) << std::endl;
	
	std::cout << std::endl;
	
	size_t pos = 0;
	Animal* animals[4];
	while (pos < 4)
	{
		if (pos < 2)
			animals[pos] = new Dog();
		else
			animals[pos] = new Cat();
		pos++;
	}

	pos = 0;
	while (pos < 4)
	{
		delete animals[pos];
		pos++;
	}
	
	std::cout << std::endl;
	
	delete dog1;
	delete dog2;
	delete cat1;
	delete cat2;

	std::cout << std::endl;

	delete randomDog1;
	delete randomCat1;
	
	std::cout << std::endl;

	Dog basicDog;
	{
		Dog tmpDog = basicDog;
	}

	Cat basicCat;
	{
		Cat tmpCat(basicCat);
	}

	std::cout << std::endl;
	
	return 0;
}