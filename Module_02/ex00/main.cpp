/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 10:00:03 by alaaouam          #+#    #+#             */
/*   Updated: 2023/07/21 11:11:43 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void) 
{
	Fixed a;
	Fixed b(a);
	Fixed c;
	Fixed d;
	
	b.setRawBits(10);
	a.setRawBits(3);
	
	c = b;
	
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	std::cout << d.getRawBits() << std::endl;
	
	return 0;
}