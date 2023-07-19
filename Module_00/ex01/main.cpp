/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:25:50 by alaaouam          #+#    #+#             */
/*   Updated: 2023/07/19 22:21:40 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "phoneBookUtils.hpp"

int	main(void)
{
	PhoneBook phoneBook;
	std::string	input;
	
	input = "";
	while (input != "EXIT")
	{
		std::cout << "Please enter an option: ";
		input = getInput();
		if (input == "ADD")
			phoneBook.add();
		else if (input == "SEARCH")
			phoneBook.search();
		else if (!std::cin.eof() && input != "EXIT")
			std::cout << "Wrong input! Try again!" << std::endl;
		if (std::cin.eof())
		{
			std::cout << std::endl;
			return (0);
		}
	}
	return (0);
}
