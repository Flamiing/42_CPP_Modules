/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 17:38:40 by alaaouam          #+#    #+#             */
/*   Updated: 2023/07/23 16:40:36 by alaaouam         ###   ########.fr       */
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
	Animal* dog1 = new Dog();
	dog1->changeIdea(0, "\"I love eating\"");
	Animal dog2 = dog1;
	dog2->changeIdea(0, "\"I love drinking\"");
	Animal* cat1 = new Cat();
	cat1->changeIdea(0, "\"I love eating\"");
	Animal cat2 = cat1;
	cat2->changeIdea(0, "\"I love drinking\"");
	
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

	std::cout << "The Dog 1 thinks: " << dog1->thinkIdea(0) << std::endl;
	std::cout << "The Dog 2 thinks: " << dog2->thinkIdea(0) << std::endl;
	std::cout << "The Cat 1 thinks: " << cat1->thinkIdea(0) << std::endl;
	std::cout << "The Cat 2 thinks: " << cat2->thinkIdea(0) << std::endl;

	delete dog1;
	//delete dog2;
	delete cat1;
	//delete cat2;

	pos = 0;
	while (pos < 4)
	{
		delete animals[pos];
		pos++;
	}
	
	return 0;
}