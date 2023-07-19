/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBookUtils.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 21:05:58 by alaaouam          #+#    #+#             */
/*   Updated: 2023/07/20 01:37:51 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

std::string	getInput(void)
{
	std::string	input;
	char	c;
	
	while (std::cin.get(c)) 
	{
		if (c == '\n')
			break ;
		input += c;
	}
	return (input);
}

void	displayContacts(Contact contacts[])
{
	int	pos;
	
	std::cout << "+===========================================+" << std::endl;
	std::cout << "|" << std::setw(10) << "INDEX" << "|" << std::setw(10) << "FIRST NAME";
	std::cout << "|" << std::setw(10) << "LAST NAME" << "|" << std::setw(10) << "NICKNAME" << "|" << std::endl;
	std::cout << "|==========|==========|==========|==========|" << std::endl;
	pos = 0;
	while (pos < 8)
	{
		std::cout << "|" << std::setw(10) << pos;
		std::cout << "|" << std::setw(11);
		if (contacts[pos].exist() == 1)
		{
			contacts[pos].displayFirstName();
			contacts[pos].displayLastName();
			contacts[pos].displayNickname();
		}
		else
			std::cout << "|" << std::setw(11)  << "|"  << std::setw(11) << "|" << std::endl;
		if (pos < 7)
			std::cout << "|==========|==========|==========|==========|" << std::endl;
		pos++;
	}
	std::cout << "+===========================================+" << std::endl;
}
