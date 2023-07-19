/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBookUtils.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 21:05:58 by alaaouam          #+#    #+#             */
/*   Updated: 2023/07/19 21:47:56 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	displayContacts(Contact contacts[])
{
	int	pos;
	
	std::cout << "+===========================================+" << std::endl;
	std::cout << "|   INDEX  |FIRST NAME| LAST NAME| NICKNAME |" << std::endl;
	std::cout << "|==========|==========|==========|==========|" << std::endl;
	pos = 0;
	while (pos < 8)
	{
		std::cout << "|" << "    " << pos;
		std::cout << "     |";
		if (contacts[pos].exist() == 1)
		{
			contacts[pos].displayFirstName();
			contacts[pos].displayLastName();
			contacts[pos].displayNickname();
		}
		else
			std::cout << "          |          |          |" << std::endl;
		if (pos < 7)
			std::cout << "|==========|==========|==========|==========|" << std::endl;
		pos++;
	}
	std::cout << "+===========================================+" << std::endl;
}
