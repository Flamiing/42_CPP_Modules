/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realType.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 03:23:37 by alaaouam          #+#    #+#             */
/*   Updated: 2023/08/04 13:38:48 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "realType.hpp"

Base* generate(void)
{
	std::srand(static_cast<unsigned int>(std::clock()));
	int randomNum = (std::rand() % (3 - 1 + 1)) + 1;;

	if (randomNum == 1)
		return (new A);
	else if (randomNum == 2)
		return (new B);
	else
		return (new C);
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "Identify by pointer: Class A" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "Identify by pointer: Class B" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "Identify by pointer: Class C" << std::endl;
}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "Identify by reference: Class A" << std::endl;
	}
	catch (std::bad_cast&) {} 
	
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "Identify by reference: Class B" << std::endl;
	}
	catch (std::bad_cast&) {} 
	
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "Identify by reference: Class C" << std::endl;
	}
	catch (std::bad_cast&) {} 
}
