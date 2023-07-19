/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:25:19 by alaaouam          #+#    #+#             */
/*   Updated: 2023/07/20 01:18:05 by alaaouam         ###   ########.fr       */
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
	std::cout << std::endl << "===============/ CONTACT \\===============" << std::endl;
	std::cout << "First Name:\t" << this->_firstName << std::endl;
	std::cout << "Last Name:\t" << this->_lastName << std::endl;
	std::cout << "Nickname:\t" << this->_nickname << std::endl;
	std::cout << "Phone Number:\t" << this->_phoneNumber << std::endl;
	std::cout << "Darkest Secret:\t" << this->_darkestSecret << std::endl << std::endl;
}

void	Contact::displayFirstName(void)
{
	std::string	resized;
	
	if (this->_firstName.length() > 10)
	{
		resized = this->_firstName;
		resized.resize(10);
		resized[9] = '.';
		std::cout << std::setw(10) << resized << "|";
	}
	else
	{
		std::cout << std::setw(10) << this->_firstName;
		std::cout << "|";
	}
}

void	Contact::displayLastName(void)
{
	std::string	resized;
	
	if (this->_lastName.length() > 10)
	{
		resized = this->_lastName;
		resized.resize(10);
		resized[9] = '.';
		std::cout << std::setw(10) << resized << "|";
	}
	else
	{
		std::cout << std::setw(10) << this->_lastName;
		std::cout << "|";
	}
}

void	Contact::displayNickname(void)
{
	std::string	resized;
	
	if (this->_nickname.length() > 10)
	{
		resized = this->_nickname;
		resized.resize(10);
		resized[9] = '.';
		std::cout << std::setw(10) << resized << "|";
	}
	else
	{
		std::cout << std::setw(10) << this->_nickname;
		std::cout << "|";
	}
	std::cout << std::endl;
}
