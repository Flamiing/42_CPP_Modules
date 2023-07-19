/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ContactUtils.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 21:16:19 by alaaouam          #+#    #+#             */
/*   Updated: 2023/07/19 21:53:37 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void	Contact::setFirstName(void)
{
	std::string	input;

	this->_exist = 1;
	input = "";
	while (!std::cin.eof())
	{
		std::cout << "Enter a first name: ";
		std::cin >> input;
		if (input != "")
		{
			this->_firstName = input;
			break ;
		}
	}
}

void	Contact::setLastName(void)
{
	std::string	input;

	input = "";
	while (!std::cin.eof())
	{
		std::cout << "Enter a last name: ";
		std::cin >> input;
		if (input != "")
		{
			this->_lastName = input;
			break ;
		}
	}
}

void	Contact::setNickname(void)
{
	std::string	input;

	input = "";
	while (!std::cin.eof())
	{
		std::cout << "Enter a nickname: ";
		std::cin >> input;
		if (input != "")
		{
			this->_nickname = input;
			break ;
		}
	}
}

void	Contact::setPhoneNumber(void)
{
	std::string	input;

	input = "";
	while (!std::cin.eof())
	{
		std::cout << "Enter a phone number: ";
		std::cin >> input;
		if (input != "")
		{
			this->_phoneNumber = input;
			break ;
		}
	}
}

void	Contact::setDarkestSecret(void)
{
	std::string	input;

	input = "";
	while (!std::cin.eof())
	{
		std::cout << "Enter " << this->_firstName << "'s darkest secret: ";
		std::cin >> input;
		if (input != "")
		{
			this->_darkestSecret = input;
			break ;
		}
	}
}
