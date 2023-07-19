/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:25:42 by alaaouam          #+#    #+#             */
/*   Updated: 2023/07/19 20:49:34 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	std::cout << "Welcome to the Phone Book!" << std::endl;
	this->_index = 0;
}

PhoneBook::~PhoneBook(void)
{
}

void	PhoneBook::add(void)
{
	Contact	newContact;
	
	newContact.setFirstName();
	newContact.setLastName();
	newContact.setNickname();
	newContact.setPhoneNumber();
	newContact.setDarkestSecret();
	std::cout << "Adding new contact to the Phone Book..." << std::endl;
	this->_contacts[this->_index % 8] = newContact;
	std::cout << "New contact succesfully added!" << std::endl;
	this->_index++;
}

void	PhoneBook::search(void)
{
	std::string	input;
	int	pos;
	
	std::cout << "+===========================================+" << std::endl;
	std::cout << "|   INDEX  |FIRST NAME| LAST NAME| NICKNAME |" << std::endl;
	std::cout << "|==========|==========|==========|==========|" << std::endl;
	pos = 0;
	while (pos < 8)
	{
		std::cout << "|" << "    " << pos;
		std::cout << "     |";
		if (this->_contacts[pos].exist() == 1)
		{
			this->_contacts[pos].displayFirstName();
			this->_contacts[pos].displayLastName();
			this->_contacts[pos].displayNickname();
		}
		else
			std::cout << "          |          |          |" << std::endl;
		if (pos < 7)
			std::cout << "|==========|==========|==========|==========|" << std::endl;
		pos++;
	}
	std::cout << "+===========================================+" << std::endl;
	while (!std::cin.eof())
	{
		std::cout << "Select an index or type 'EXIT' to leave: ";
		std::cin >> input;
		if (input == "EXIT")
			break ;
		if (input.size() == 1 && input[0] >= '0' && input[0] <= '7' && this->_contacts[input[0] - '0'].exist() == 1)
		{
			this->_contacts[input[0] - '0'].printContact();
			break ;
		}
		else
			std::cout << "Wrong index!" << std::endl;
	}
}
