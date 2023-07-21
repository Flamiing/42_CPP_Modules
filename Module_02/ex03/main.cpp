/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 10:00:03 by alaaouam          #+#    #+#             */
/*   Updated: 2023/07/21 19:44:23 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

void printBoolean(bool result)
{
	static int count = 1;
	
	std::cout << "Test " << count << ":\t";
	if (result)
		std::cout << "True :)" << std::endl;
	else
		std::cout << "False :(" << std::endl;
	count++;
}

int	main( void )
{
	Point const	aVertex(1.2f, 3.5f);
	Point const	bVertex(-2.9f, 0.8f);
	Point const	cVertex(4.5f, -2.1f);
	
	Point const	pointTest1(0.96f, 1.01f);
	Point const	pointTest2(-0.5f, 4.4366f);
	Point const	pointTest3(2.66f, 1.73f);
	Point const	pointTest4(aVertex);
	Point const	pointTest5(0.55f, 0.74f);

	printBoolean(bsp(aVertex, bVertex, cVertex, pointTest1));
	printBoolean(bsp(aVertex, bVertex, cVertex, pointTest2));
	printBoolean(bsp(aVertex, bVertex, cVertex, pointTest3));
	printBoolean(bsp(aVertex, bVertex, cVertex, pointTest4));
	printBoolean(bsp(aVertex, bVertex, cVertex, pointTest5));
	
	return (0);
}
