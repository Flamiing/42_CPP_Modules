/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 10:00:03 by alaaouam          #+#    #+#             */
/*   Updated: 2023/07/24 00:40:38 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void) 
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2) );
	Fixed c(10);
	Fixed d(2);
	
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	
	std::cout << b << std::endl;
	
	std::cout << c / d << std::endl;
	std::cout << c + d << std::endl;
	std::cout << c - d << std::endl;
	
	std::cout << Fixed::max(a, b) << std::endl;
	std::cout << Fixed::min(c, d) << std::endl;

	a--;
	std::cout << a << std::endl;
	--a;
	std::cout << a << std::endl;

	if (c > d)
		std::cout << "Is bigger" << std::endl;
	if (d < c)
		std::cout << "Is smaller" << std::endl;
	if (d <= c)
		std::cout << "Is smaller or equal" << std::endl;
	if (c >= d)
		std::cout << "Is bigger or equal" << std::endl;
	if (c == c)
		std::cout << "Is equal" << std::endl;
	if (c != d)
		std::cout << "Is not equal" << std::endl;
	
	return 0;
}
