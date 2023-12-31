/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:25:42 by alaaouam          #+#    #+#             */
/*   Updated: 2023/07/20 01:34:59 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "phoneBookUtils.hpp"

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
	
	if (this->_index > 7)
		std::cout << "WARNING: The oldest contact will be replaced by the new one" << std::endl;
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

	displayContacts(this->_contacts);
	while (!std::cin.eof())
	{
		std::cout << "Select an index or type 'EXIT' to leave: ";
		input = getInput();
		if (input == "EXIT")
			break ;
		if (input.size() == 1 && input[0] >= '0' && input[0] <= '7' && this->_contacts[input[0] - '0'].exist() == 1)
		{
			this->_contacts[input[0] - '0'].printContact();
			break ;
		}
		else if (!std::cin.eof())
		{
			if (this->_contacts[0].exist() == 0)
			{
				if (input[0] >= '0' && input[0] <= '7')
					std::cout << "There are no contacts" << std::endl;
				else
					std::cout << "\"" << input << "\" is not a valid index!" << std::endl;
				break ;
			}
			else
				std::cout << "Invalid index! Try again!" << std::endl;
		}
	}
}
