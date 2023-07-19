/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:25:50 by alaaouam          #+#    #+#             */
/*   Updated: 2023/07/19 21:57:04 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook phoneBook;
	std::string	input;
	
	input = "";
	while (input != "EXIT")
	{
		std::cout << "Please enter an option: ";
		std::cin >> input;
		if (input == "ADD")
			phoneBook.add();
		else if (input == "SEARCH")
			phoneBook.search();
		else if (!std::cin.eof() && input != "EXIT")
			std::cout << "Wrong input!" << std::endl;
		if (std::cin.eof())
		{
			std::cout << std::endl;
			return (0);
		}
	}
	return (0);
}
