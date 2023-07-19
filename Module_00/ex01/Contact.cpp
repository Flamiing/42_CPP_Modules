/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:25:19 by alaaouam          #+#    #+#             */
/*   Updated: 2023/07/19 21:16:39 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
	this->_exist = 0;
}

Contact::~Contact(void)
{
}

int	Contact::exist(void)
{
	return (this->_exist);
}

void	Contact::printContact(void)
{
	std::cout << "First Name:\t" << this->_firstName << std::endl;
	std::cout << "Last Name:\t" << this->_lastName << std::endl;
	std::cout << "Nickname:\t" << this->_nickname << std::endl;
	std::cout << "Phone Number:\t" << this->_phoneNumber << std::endl;
	std::cout << "Darkest Secret:\t" << this->_darkestSecret << std::endl;
}

void	Contact::displayFirstName(void)
{
	size_t	count;
	
	count = 0;
	if (this->_firstName.length() > 10)
	{
		this->_firstName.resize(9);
		std::cout << this->_firstName << ".|";
	}
	else
	{
		std::cout << this->_firstName;
		while (count < (10 - this->_firstName.length()))
		{
			std::cout << " ";
			count++;
		}
		std::cout << "|";
	}
}

void	Contact::displayLastName(void)
{
	size_t	count;
	
	count = 0;
	if (this->_lastName.length() > 10)
	{
		this->_lastName.resize(9);
		std::cout << this->_lastName << ".|";
	}
	else
	{
		std::cout << this->_lastName;
		count = 0;
		while (count < (10 - this->_lastName.length()))
		{
			std::cout << " ";
			count++;
		}
		std::cout << "|";
	}
}

void	Contact::displayNickname(void)
{
	size_t	count;
	
	count = 0;
	if (this->_nickname.length() > 10)
	{
		this->_nickname.resize(9);
		std::cout << this->_nickname << ".|";
	}
	else
	{
		std::cout << this->_nickname;
		count = 0;
		while (count < (10 - this->_nickname.length()))
		{
			std::cout << " ";
			count++;
		}
		std::cout << "|";
	}
	std::cout << std::endl;
}
